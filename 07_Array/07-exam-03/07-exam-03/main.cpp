/*
HDOJ 2022 海选女主角
https://acm.hdu.edu.cn/showproblem.php?pid=2022
*/

#include <iostream>
#include <cmath>
using namespace std;

int a[1000][1000];

int main() {
	int m, n;
	while (cin >> m >> n) {
		int max = -1, r, c;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int x = abs(a[i][j]);
				if (x > max) {
					max = x;
					r = i;
					c = j;
				}
			}
		}
		cout << r + 1 << ' ' << c + 1 << ' ' << a[r][c] << endl;
	}
	return 0;
}