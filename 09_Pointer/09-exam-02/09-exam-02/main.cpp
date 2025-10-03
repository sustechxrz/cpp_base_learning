/*
HDOJ 2099 整除的尾数
https://acm.hdu.edu.cn/showproblem.php?pid=2099

一个整数，只知道前几位，
不知道末二位，被另一个整数除尽了，
那么该数的末二位该是什么呢？

输入:不断输入数据，一行两个整数a, b, （0<a<10000, 10<b<100），若遇到0 0则处理结束。
输出:满足条件的所有尾数在一行内输出，同组数据的输出，其每个尾数之间空一格，行末没有空格

*/

#include <iostream>
using namespace std;

int* clacNail(int a, int b, int* returnSize) {   //指针函数 返回值为指针的函数 返回值代表结果数组的首地址 returnSize是外部传进来的提前定义的代表结果数组大小的地址
	*returnSize = 0;							 //把提前定义的代表结果数组的大小的值进行初始化
	int* ret = new int[100];					 //申请一个动态数组内存，最多100个元素
	for (int i = 0; i < 100; ++i) {				 //枚举所有的两位数，判断是否整除，若是则加入结果数组
		if (((a * 100 + i) % b) == 0) {
			ret[(*returnSize)++] = i;			 //(returnSize++)代表结果数组的大小+1
		}
	}
	return ret;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (!a && !b) {
			break;
		}
		int size;
		int* ret = clacNail(a, b, &size);
		for (int i = 0; i < size; ++i) {
			if (i) {
				cout << ' ';
			}
			if (ret[i] < 10) {
				cout << '0';
			}
			cout << ret[i];
		}
		cout << endl;
		delete[] ret;
	}

	return 0;
}