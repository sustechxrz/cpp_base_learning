#include <iostream>
using namespace std;

int main() {
	int i = 6;
	i++;
	cout << i << endl;
	++i;
	cout << i << endl;

	int j = 8;
	int x = i++; // �Ȱ�ֵ����x����ִ�е���
	int y = ++j; // ��ִ�е������ٰ�ֵ����y��Ч����΢��һ��㣩
	cout << x << endl << y << endl;
	
	int z = (i++) + (++i);// 9 + 11 = 20
	cout << z << endl;
	return 0;
}