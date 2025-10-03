/*
HDOJ 2099 ������β��
https://acm.hdu.edu.cn/showproblem.php?pid=2099

һ��������ֻ֪��ǰ��λ��
��֪��ĩ��λ������һ�����������ˣ�
��ô������ĩ��λ����ʲô�أ�

����:�����������ݣ�һ����������a, b, ��0<a<10000, 10<b<100����������0 0���������
���:��������������β����һ���������ͬ�����ݵ��������ÿ��β��֮���һ����ĩû�пո�

*/

#include <iostream>
using namespace std;

int* clacNail(int a, int b, int* returnSize) {   //ָ�뺯�� ����ֵΪָ��ĺ��� ����ֵ������������׵�ַ returnSize���ⲿ����������ǰ����Ĵ����������С�ĵ�ַ
	*returnSize = 0;							 //����ǰ����Ĵ���������Ĵ�С��ֵ���г�ʼ��
	int* ret = new int[100];					 //����һ����̬�����ڴ棬���100��Ԫ��
	for (int i = 0; i < 100; ++i) {				 //ö�����е���λ�����ж��Ƿ����������������������
		if (((a * 100 + i) % b) == 0) {
			ret[(*returnSize)++] = i;			 //(returnSize++)����������Ĵ�С+1
		}
	}
	return ret;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (!a && !b) {
			break;
		}
		int size;
		int* ret = clacNail(a, b, &size);
		for (int i = 0; i < size; ++i) {
			if (i) {
				cout << ' ';
			}
			if (ret[i] < 10) {
				cout << '0';
			}
			cout << ret[i];
		}
		cout << endl;
		delete[] ret;
	}

	return 0;
}