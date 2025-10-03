#include <iostream>
using namespace std;

int main() {
	int (*p)[5];
	int a[4][5] = {
		{4,3,2,1,0},
		{9,8,7,6,5},
		{6,7,8,9,0},
		{5,6,7,8,9}
	};
	p = a;
	cout << p << endl;		//D0  -> DF  ->E4
	cout << p + 1 << endl;  //E4
	// 20¸ö×Ö½Ú
	// 20 = 4 * 5 = sizeof(int) * 5
	cout << p[0] << endl;
	return 0;
}