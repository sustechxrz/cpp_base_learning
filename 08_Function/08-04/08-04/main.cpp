#include <iostream>
using namespace std;

//����
int add(int, int);

int main() {
	int x, y;
	cin >> x >> y;
	int z = add(x, y);
	cout << z << endl;

	return 0;
}

int add(int a, int b) {
	return a + b;
}