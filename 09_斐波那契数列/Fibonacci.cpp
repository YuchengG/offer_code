/************************************************************************/
/* Fibonacci数列f(0)=0,f(1)=1,f(n)=f(n-1)+f(n-2)，常用的方法有基于递归的
方法和基于循环的算法，递归的算法比较容易写，但是因为函数调用是有很大的时
间空间的消耗，而且往系统栈里压入和取出元素都需要时间消耗，故递归是一种效
率比较低的实现算法*/
/************************************************************************/
#include <iostream>
#include <time.h>
using namespace std;
long long Fibonacci_rec(unsigned int n){
	if(n<=0)
		return 0;
	if (n==1)
	{
		return 1;
	}
	return Fibonacci_rec(n-1)+Fibonacci_rec(n-2);
}

long long Fibonacci_loop(unsigned int n){
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	long long F_one=0;
	long long F_two=1;
	long long F_new=0;
	for(int i=2;i<=n;i++){
		F_new=F_one+F_two;
		F_one=F_two;
		F_two=F_new;
		
	}
	return F_new;
}

void main(){
	clock_t start,finish;
	start=clock();
	cout<< "10 Fibonacci is:"<<Fibonacci_rec(50)<<endl;
	finish=clock();
	cout<< "The time consume is:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
	start=clock();
	cout<< "10 Fibonacci is:"<<Fibonacci_loop(50)<<endl;
	finish=clock();
	cout<< "The time consume is:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
}
