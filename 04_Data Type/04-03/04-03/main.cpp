#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
float    4字节 0000
double   8字节 00000000

*/

#define eps 1e-7 //精度

int main() {
	float a = 3.1415926f;
	double b = 3.14159261111111111111111111111111111111111;
	double c = 1.5e5; // 1.5*10^5
	double d = 1.5e-5; // 1.5*10^-5
	cout << setprecision(10) << a << endl;
	cout << setprecision(26) << b << endl;
	cout << c << endl;
	cout << d << endl;
	double x = 1.0 / 127834127 * 127834127;
	//fabs 取绝对值
	if (fabs(x - 1) < eps) {
		cout << "hhh" << endl;
	}
	cout << x << endl;

	return 0;
}