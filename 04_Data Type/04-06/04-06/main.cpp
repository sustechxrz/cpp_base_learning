#include <iostream>
#include <string>
using namespace std;

/*
char ������[] = "�ַ�������";

*/


int main() {
	char a[] = "�������㷨����";
	cout << sizeof(a) << endl;
	cout << a << endl;

	string b = "ҹ";
	cout << b + ";" << endl;
	cout << sizeof(b) << endl;
	return 0;
}