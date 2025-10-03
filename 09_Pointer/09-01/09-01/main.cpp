#include <iostream>
using namespace std;

int main() {
	int a = 10;
	char b;
	cout << &a << endl;
	//cout << &b << endl;
	printf("%#X", &b);
	cout << endl << sizeof(a) << sizeof(b);
	return 0;
}