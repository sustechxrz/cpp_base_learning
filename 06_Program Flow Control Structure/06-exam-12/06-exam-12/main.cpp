/*
HDOJ 2075 A|B?
https://acm.hdu.edu.cn/showproblem.php?pid=2075
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int x = a % b;
		cout << (x == 0 ? "YES" : "NO") << endl;
	}
	return 0;
}