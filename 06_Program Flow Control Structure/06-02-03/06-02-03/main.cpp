#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int sum = 0;
		int i = 1;
		for (; i <= n; ++i) {
			sum += i;
		}
		cout << sum << endl;
	}

	return 0;
}