/************************************************************************/
/* ������Ч�ؼ���һ����������1�ĸ�����
����1��ÿһλ��1�����������Ϊ1��count++��������������
����2��һ��������ȥ1Ȼ����ԭ�����������㣬(n-1)&n�����Ĵ�����Ϊ����Ϊ1�ĸ���*/
/************************************************************************/
#include <iostream>
using namespace std;
int numberof1solution1(int n){
	int count=0;
	unsigned int flag=1;
	while(flag){
		if(n&flag)
			++count;
		flag=flag<<1;
	}
	return count;
}

int numberof1solution2(int n){
	int count=0;
	while(n){
		++count;
		n=(n-1)&n;
	}
	return count;
}

void main(){
	cout<<"the 1 in bin of 10 "<<numberof1solution1(10)<<endl;
	cout<<"the 1 in bin of 101 "<<numberof1solution1(101)<<endl;
	cout<<"the 1 in bin of 0x7FFFFFFF "<<numberof1solution1(0x7FFFFFFF)<<endl;
	cout<<"the 1 in bin of 10 "<<numberof1solution2(10)<<endl;
	cout<<"the 1 in bin of 101 "<<numberof1solution2(101)<<endl;
	cout<<"the 1 in bin of 0x7FFFFFFF "<<numberof1solution2(0x7FFFFFFF)<<endl;
}