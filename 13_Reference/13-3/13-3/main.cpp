#include <iostream>
using namespace std;

//���� ������
//���õĵײ�ʵ�־���һ��ָ�볣��
//ָ�볣��:ָ����ָ��ĵ�ַ��һ������ �޷����޸�Ϊ��ı����ĵ�ַ
//����ָ��:ָ������ָ��
int main() {
	int a = 520;
	//int& b = a;// 00007FF79E201865  lea         rax,[a]  
	           // 00007FF79E201869  mov         qword ptr[b], rax
	//b = 1314;  // 00007FF79E20186D  mov         rax,qword ptr [b]  
	           // 00007FF79E201871  mov         dword ptr[rax], 522h
	int* const b = &a;// 00007FF78E881865  lea         rax,[a]  
	                  // 00007FF78E881869  mov         qword ptr[b], rax
	*b = 1314;// 00007FF78E88186D  mov         rax,qword ptr [b]  
	          // 00007FF78E881871  mov         dword ptr[rax], 522h

	return 0;
}