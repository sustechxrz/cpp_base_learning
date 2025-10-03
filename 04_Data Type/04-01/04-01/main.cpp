#include <iostream>
using namespace std;

/*

           一个字节8位
short     2字节 00       2^16(-32768 -> 32767)
int       4字节 0000     2^32(-2^31 -> 2^31-1)
long      windows系统4字节 0000/Linux 可能4或8  2^32(-2^31 -> 2^31-1)
long long 8字节 00000000 2^64(-2^63 -> 2^63-1)

*/

int main() {
	short a = 32769;
	int b = 1;
	long c = 1;
	long long d = 1;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "---" << endl;

	int e = 0b11111111111111111111111111111111;
	int f = 0b10000000000000000000000000000000;
	int g = 0b11000000000000000000000000000000;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	return 0;
}