/*
HDOJ 2037 ΩÒƒÍ ÓºŸ≤ªAC
https://acm.hdu.edu.cn/showproblem.php?pid=2037
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct program {
	int s, e;
}I[100];

bool cmp(const program& a, const program& b) {
	return a.e < b.e;
}

int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) {
			cin >> I[i].s >> I[i].e;
		}
		sort(I, I + n, cmp);
		int ans = 0;
		int end = -1;
		for (int i = 0; i < n; ++i) {
			if (I[i].s >= end) {
				ans++;
				end = I[i].e;
			}
		}
		cout << ans << endl;
	}


	return 0;
}