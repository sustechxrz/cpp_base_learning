/*
HDOJ 2033 »Àº˚»À∞ÆA+B
https://acm.hdu.edu.cn/showproblem.php?pid=2033
*/

#include <iostream>
using namespace std;

int main() {
	int n, ah, am, as, bh, bm, bs;
	int a, b, c;
	cin >> n;
	while (n--) {
		cin >> ah >> am >> as >> bh >> bm >> bs;
		int c1,b1;
		c1 = as + bs;
		c = c1 % 60;
		b1 = am + bm + c1 / 60;
		b = b1 % 60;
		a = ah + bh + b1 / 60;
		cout << a << ' ' << b << ' ' << c << ' ' << endl;
		
	}

	return 0;
}