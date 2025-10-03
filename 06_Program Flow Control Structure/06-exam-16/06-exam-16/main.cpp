/*
HDOJ 2071 Max Num
https://acm.hdu.edu.cn/showproblem.php?pid=2071
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double x;
		double max = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x > max) {
				max = x;
			}
		}
		//printf("%.2lf\n", max);
		cout << fixed << setprecision(2) << max << endl;
	}

	return 0;
}