/*
HDOJ 2081 �ֻ��̺�
https://acm.hdu.edu.cn/showproblem.php?pid=2081

����:����n�����ݣ�ÿ��Ϊһ��11λ���ֻ�����
���:n�У�ÿ��Ϊ6+�ֻ��ź�5λ�����Ӧ�������˳��һ�¡�
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		char s[12];
		cin >> s;
		cout << '6' << s + 6;//ָ���ƫ��
		if (n) {
			cout << endl;
		}
	}


	return 0;
}