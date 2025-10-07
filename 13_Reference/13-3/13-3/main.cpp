#include <iostream>
using namespace std;

//引用 解引用
//引用的底层实现就是一个指针常量
//指针常量:指针所指向的地址是一个常量 无法再修改为别的变量的地址
//常量指针:指向常量的指针
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