#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int b = 20;
	//1.ָ������Ķ���
	//2.��������* ָ�������
	int* pa;
	pa = &a;
	//cout << &a << ' ' << pa << endl;
	printf("%#X %#X\n", &a, pa);

	//2.������
	//*ָ������� = ��ֵ
	*pa = 7;
	cout << a << ' ' << (*pa) << endl;
	cout << "----------" << endl;

	//3. * �� &
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