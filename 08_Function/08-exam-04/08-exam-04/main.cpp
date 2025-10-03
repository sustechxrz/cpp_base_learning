/*
HDOJ 三角形 2039
https://acm.hdu.edu.cn/showproblem.php?pid=2039

输入：不断输入t组数据，每组包含三个正数A，B，C
输出：对每组数据，若三个数能组成三角形，输出YES，否则NO

*/

#include <iostream>
#include <algorithm>
using namespace std;

double a[3];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);//左闭右开
		if (a[0] + a[1] > a[2]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;

}