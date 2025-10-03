/*
HDOJ 2052 Picture
https://acm.hdu.edu.cn/showproblem.php?pid=2052
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		string a = "\0";
		string b = "\0";
		while (n--)
		{
			a += '-';
			b += ' ';
		}
		cout << '+' << a << '+' << endl;
		while (m--)
		{
			cout << '|' << b << '|' << endl;
		}
		cout << '+' << a << '+' << endl;
		cout << endl;
	}
	return 0;
}