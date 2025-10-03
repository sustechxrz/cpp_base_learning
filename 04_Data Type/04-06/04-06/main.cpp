#include <iostream>
#include <string>
using namespace std;

/*
char 变量名[] = "字符串常量";

*/


int main() {
	char a[] = "仙人掌算法联盟";
	cout << sizeof(a) << endl;
	cout << a << endl;

	string b = "夜";
	cout << b + ";" << endl;
	cout << sizeof(b) << endl;
	return 0;
}