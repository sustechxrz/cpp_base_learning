#include <iostream>
#include <string>
// i = input
// o = output
using namespace std;

int main() {
	// 1.���͵�����
	int a = 5;
	cin >> a;
	cout << "a��ֵ�����:" << a << endl;
	// 2.�����͵�����
	double b = 7;
	cin >> b;
	cout << "b��ֵ�����:" << b << endl;
	// 3.�ַ��͵�����
	char c = 7;
	cin >> c;
	cout << "c��ֵ�����:" << c << endl;
	// 4.�ַ�����
	string d = "";
	cin >> d;
	cout << "d��ֵ�����:" << d << endl;
	// 5.��������
	bool e = false;
	cin >> e;
	cout << "e��ֵ�����:" << e << endl;
	string f;
	cin >> f;
	cout << "f��ֵ�����:" << f << endl;
	return 0;
}