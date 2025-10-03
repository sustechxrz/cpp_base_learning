/*
HDOJ 2004 ³É¼¨×ª»»
https://acm.hdu.edu.cn/showproblem.php?pid=2004
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	while (cin >> t) {
		char x = '\0';
		if (t >= 90 && t <= 100) {
			x = 'A';
		}
		else if (t >= 80 && t <= 89) {
			x = 'B';
		}
		else if (t >= 70 && t <= 79) {
			x = 'C';
		}
		else if (t >= 60 && t <= 69) {
			x = 'D';
		}
		else if (t >= 0 && t <= 59) {
			x = 'E';
		}
		if (x == '\0') {
			cout << "Score is error!" << endl;
		}
		else {
			cout << x << endl;
		}
	}

	return 0;
}