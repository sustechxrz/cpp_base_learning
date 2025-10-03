/*
HDOJ 2007 平方和与立方和
https://acm.hdu.edu.cn/showproblem.php?pid=2007
*/

#include <iostream>
using namespace std;

int a[1000000];

int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m > n) {
			int tmp = n; n = m; m = tmp;
		}
		int cnt = n - m + 1;
		for (int i = m; i <= n; ++i) {
			a[i - m] = i;
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < cnt; i++) {
			if (a[i] % 2 == 0) {
				sum1 += a[i] * a[i];
			}
			else {
				sum2 += a[i] * a[i] * a[i];
			}
		}
		cout << sum1 << ' ' << sum2 << endl;
		/* 
		int x = 0;
		int y = 0;
		for (int i = m; i <= n; ++i) {
			if (i % 2) {
				y += i * i * i;
			}
			else {
				x += i * i;
			}
		}
		cout << x << ' ' << y << endl;
		*/
	}

	return 0;
}