/************************************************************************/
/* Fibonacci����f(0)=0,f(1)=1,f(n)=f(n-1)+f(n-2)�����õķ����л��ڵݹ��
�����ͻ���ѭ�����㷨���ݹ���㷨�Ƚ�����д��������Ϊ�����������кܴ��ʱ
��ռ�����ģ�������ϵͳջ��ѹ���ȡ��Ԫ�ض���Ҫʱ�����ģ��ʵݹ���һ��Ч
�ʱȽϵ͵�ʵ���㷨*/
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
