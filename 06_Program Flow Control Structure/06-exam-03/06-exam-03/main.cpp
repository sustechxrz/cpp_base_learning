/*
HDOJ 1090 A+B for Input-Output Practice (II)
https://acm.hdu.edu.cn/showproblem.php?pid=1090

输入:输入一个N，然后输入N组数据，每组数据是a和b
输出：N行，每行是a+b的和

*/


#include <iostream>
using namespace std;

int main() {
	int N,a,b;
	cin >> N;
	while (N--) {
		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;

}