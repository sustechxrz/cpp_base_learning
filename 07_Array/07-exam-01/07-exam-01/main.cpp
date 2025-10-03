/*
HDOJ 2006 求奇数的乘积
https://acm.hdu.edu.cn/showproblem.php?pid=2006
*/

#include <iostream>
using namespace std;

int a[10000000];

int main() {
	int n;
	while (cin >> n) {
		int prod = 1;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] % 2) {
				prod *= a[i];
			}
		}
		cout << prod << endl;
	}

	return 0;
}