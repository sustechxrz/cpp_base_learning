
/*
HDOJ 1092 A+B for Input-Output Practice (IV)
https://acm.hdu.edu.cn/showproblem.php?pid=1092
*/

#include <iostream>
using namespace std;

int main() {
	int n, x, sum;
	while (cin >> n && n) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			sum += x;
		}
		cout << sum << endl;
	}

	return 0;
}