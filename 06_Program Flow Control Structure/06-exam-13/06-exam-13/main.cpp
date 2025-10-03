/*
HDOJ 2055 An easy problem
https://acm.hdu.edu.cn/showproblem.php?pid=2055
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		char x;
		int y;
		int ans = 0;
		cin >> x >> y;
		if (x >= 'A' && x <= 'Z') {
			ans = y + (x - 'A' + 1);
		}
		else if (x >= 'a' && x <= 'z') {
			ans = y - (x - 'a' + 1);
		}
		cout << ans << endl;
	}
	


	return 0;
}