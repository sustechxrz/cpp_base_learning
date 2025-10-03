#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int b = 20;
	//1.指针变量的定义
	//2.数据类型* 指针变量名
	int* pa;
	pa = &a;
	//cout << &a << ' ' << pa << endl;
	printf("%#X %#X\n", &a, pa);

	//2.解引用
	//*指针变量名 = 数值
	*pa = 7;
	cout << a << ' ' << (*pa) << endl;
	cout << "----------" << endl;

	//3. * 和 &
	// *&a = *(&a) = *pa = a;
	// &*pa = &(*pa) = &a = pa;
	cout << (*&a) << endl;
	cout << (*(&a)) << endl;
	cout << (*pa) << endl;
	cout << (a) << endl;
	cout << "----------" << endl;
	cout << (&*pa) << endl;
	cout << (&(*pa)) << endl;
	cout << (&a) << endl;
	cout << (pa) << endl;

	return 0;
}