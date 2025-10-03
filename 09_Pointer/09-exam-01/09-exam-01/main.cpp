/*
HDOJ 2081 手机短号
https://acm.hdu.edu.cn/showproblem.php?pid=2081

输入:输入n行数据，每行为一个11位的手机号码
输出:n行，每行为6+手机号后5位，输出应与输入的顺序一致。
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		char s[12];
		cin >> s;
		cout << '6' << s + 6;//指针的偏移
		if (n) {
			cout << endl;
		}
	}


	return 0;
}