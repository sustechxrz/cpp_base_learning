#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define H 27
#define W 60

const int dir[4][2] = {
	{-1,0},   //上
	{0,1},    //右
	{1,0},    //下
	{0,-1}    //左
};

enum BlockType {
	EMPTY = 0,
	FOOD = 1,
};

struct Map {
	BlockType data[H][W];
	bool hasFood;
};

struct Pos {
	int x;
	int y;
};

struct Snake {
	Pos snake[H * W];
	int snakeDir;
	int snakeLength;
	int lastMoveTime;
	int moveFrequency;
};

void initSnake(Snake* snk) {
	snk->snakeLength = 3;
	snk->snakeDir = 1;
	snk->snake[0] = { W / 2,H / 2 };
	snk->snake[1] = { W / 2 - 1,H / 2 };
	snk->snake[2] = { W / 2 - 2,H / 2 };
	snk->lastMoveTime = 0;
	snk->moveFrequency = 200;
}

void hideCursor() {
	//句柄（Handle） 是一个广义的概念，通常用于表示对某个资源的引用。
	//句柄的本质是一个整数值，通过这个整数值可以间接地访问到实际的资源对象。
	// 在 Windows 系统中，句柄是一个 32 位的无符号整数值，
	// 用于唯一标识系统中的各种资源，如窗口、图标、光标等。
	// 当系统创建这些资源时，会为它们分配内存，并返回一个标识这些资源的句柄。
	// 句柄是固定的，不会随资源的位置变化而变化，因此可以通过句柄来记录资源的最新地址。
	//获取标准输出句柄
	//GetStdHandle 是一个关键的API函数，它允许程序获取标准输入、标准输出或标准错误的句柄。
	//这些句柄是识别不同设备的数值，对于需要读取或写入控制台的应用程序来说至关重要。
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定义光标信息结构体 并设置大小为1且不可见
	//CONSOLE_CURSOR_INFO 结构体包含了控制台光标的信息。
	// 它有两个成员：dwSize 和 bVisible。
	// dwSize 是一个 DWORD 类型，表示光标填充字符单元格的百分比，这个值介于1到100之间。
	// 光标的外观会随着 dwSize 值的变化而变化，从完全填充单元格到显示为单元格底部的水平线。
	// bVisible 是一个 BOOL 类型，表示光标是否可见，如果光标可见，则此成员为 TRUE。
	CONSOLE_CURSOR_INFO curInfo = { 1,FALSE };
	//应用设置
	SetConsoleCursorInfo(hOutput, &curInfo);
}

void initMap(Map* map) {
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			map->data[y][x] = BlockType::EMPTY;
		}
	}
	map->hasFood = false;
}

void drawUnit(Pos p, const char unit[]) {
	COORD coord;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = p.x + 1;
	coord.Y = p.y + 1;
	SetConsoleCursorPosition(hOutput, coord);
	cout << unit;
}

void drawMap(Map* map) {
	system("cls");
	//┐└┘┌│─
	cout << "┌";
	for (int i = 0; i < W; ++i) {
		cout << "─";
	}
	cout << "┐" << endl;
	for (int y = 0; y < H; ++y) {
		cout << "│";
		for (int x = 0; x < W; ++x) {
			if(map->data[y][x] == BlockType::EMPTY)
			cout << " ";
		}
		cout << "│" << endl;
	}
	cout << "└";
	for (int i = 0; i < W; ++i) {
		cout << "─";
	}
	cout << "┘" << endl;
}

void drawSnake(Snake* snk) {
	for (int i = 0; i < snk->snakeLength; ++i) {
		drawUnit(snk->snake[i], "+");
	}
}

bool checkOutOfBound(Pos p) {
	return (p.x <= 0 || p.x >= W + 1 || p.y <= 0 || p.y >= H + 1);
}

void checkEatFood(Snake* snk, Pos tail, Map* map) {
	Pos head = snk->snake[0];
	if (map->data[head.y][head.x] == BlockType::FOOD) {
		snk->snake[snk->snakeLength++] = tail;
		map->data[head.y][head.x] = BlockType::EMPTY;
		map->hasFood = false;
		drawUnit(tail, "+");
	}
}

void moveSnake(Snake* snk) {
	for (int i = snk->snakeLength - 1; i >= 1; --i) {
		snk->snake[i] = snk->snake[i - 1];
	}
	snk->snake[0].y += dir[snk->snakeDir][0];
	snk->snake[0].x += dir[snk->snakeDir][1];
}

bool doMove(Snake* snk, Map* map) {
	Pos tail = snk->snake[snk->snakeLength - 1];
	drawUnit(tail, " ");
	moveSnake(snk);
	if (checkOutOfBound(snk->snake[0])) {
		return false;
	}
	checkEatFood(snk, tail, map);
	drawUnit(snk->snake[0], "+");
	return true;
}

bool checkSnakeMove(Snake* snk, Map* map) {
	int curTime = GetTickCount();
	if (curTime - snk->lastMoveTime > snk->moveFrequency) {
		if(false == doMove(snk, map))
			return false;
		snk->lastMoveTime = curTime;
	}
	return true;
}

void checkChangeDir(Snake* snk) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if(snk->snakeDir != 2)
			snk->snakeDir = 0;
			break;
		case 'd':
			if (snk->snakeDir != 3)
			snk->snakeDir = 1;
			break;
		case 's':
			if (snk->snakeDir != 0)
			snk->snakeDir = 2;
			break;
		case 'a':
			if (snk->snakeDir != 1)
			snk->snakeDir = 3;
			break;
		default:
			break;
		}
	}
}

void checkFoodGenerate(Snake* snk, Map* map) {
	if (false == map->hasFood) {
		while (1) {
			int x = rand() % W;
			int y = rand() % H;
			int i = 0;
			while (i < snk->snakeLength) {
				if (x == snk->snake[i].x && y == snk->snake[i].y) {
					break;
				}
				i++;
			}
			if (i == snk->snakeLength) {
				map->data[y][x] = BlockType::FOOD;
				map->hasFood = true;
				drawUnit({ x,y }, "+");
				return;
			}
		}
	}
}

void initGame(Snake* snk, Map* map) {
	hideCursor();
	initMap(map);
	initSnake(snk);
	drawMap(map);
	drawSnake(snk);
}

int main() {
	Map map;
	Snake snk;
	initGame(&snk, &map);
	while (1) {
		checkChangeDir(&snk);
		if (false == checkSnakeMove(&snk, &map)) {
			break;
		}
		checkFoodGenerate(&snk, &map);
	}
	drawUnit({ W / 2 - 4,H / 2 }, "Game Over");
	while(1){}
	return 0;
}