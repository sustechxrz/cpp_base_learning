/*
HDOJ 1093 A+B for Input-Output Practice (V)
https://acm.hdu.edu.cn/showproblem.php?pid=1093
*/

#include <iostream>
using namespace std;

int main() {
	int n, m, x, sum;
	while (cin >> n) {
		while (cin >> m) {
			sum = 0;
			for (int i = 0; i < m; ++i) {
				cin >> x;
				sum += x;
			}
			cout << sum << endl;
		}
	}

	return 0;
}