/*
HDOJ 1091 A+B for Input-Output Practice (III)
https://acm.hdu.edu.cn/showproblem.php?pid=1091
*/


#include <iostream>
using namespace std;

int main() {
	int a, b;
	while ((cin >> a >> b) && (a || b)) {
		cout << a + b << endl;
	}

	return 0;
}