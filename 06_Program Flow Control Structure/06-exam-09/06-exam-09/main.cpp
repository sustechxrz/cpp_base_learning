
/*
HDOJ 1096 A+B for Input-Output Practice (VIII)
https://acm.hdu.edu.cn/showproblem.php?pid=1096
*/

#include <iostream>
using namespace std;

int main() {
	int t, n, x, sum;
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			sum += x;
		}
		cout << sum << endl;
	}

	return 0;
}