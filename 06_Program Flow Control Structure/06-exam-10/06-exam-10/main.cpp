
/*
HDOJ 2096 Ð¡Ã÷A+B
https://acm.hdu.edu.cn/showproblem.php?pid=2096
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b,sum;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		sum = (a % 100) + (b % 100);
		sum = sum % 100;
		cout << sum << endl;
	}

	return 0;
}