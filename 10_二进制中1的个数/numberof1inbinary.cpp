/************************************************************************/
/* 快速有效地计算一个二进制中1的个数：
方法1：每一位与1做与操作，若为1则count++，否则不做操作；
方法2：一个整数减去1然后与原整数做与运算，(n-1)&n操作的次数即为其中为1的个数*/
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