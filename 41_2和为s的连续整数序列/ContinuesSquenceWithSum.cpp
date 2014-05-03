#include <iostream>
using namespace std;
void PrintContinuousSequence(int small,int big);
void FindConttinuousSequence(int sum){
	if(sum <3)
		return;
	int small=1;
	int big=2;
	int middle=(1+sum)/2;
	int curSum=small+big;
	//同前一个方法差不多，如果small到big的序列的和小于s，那么我们增大big，大于s则增大small，找到后，然后增加big的数字重新重复前面步骤，
	//因为可能存在下一组符合的情况,例如9 在找到2，3，4，增大big为5，之后会找到4，5直到small大于5则停止循环得到4，5.
	while(small<middle){
		if(curSum==sum){
			PrintContinuousSequence(small,big);
			cout<<endl;
		}
		while(curSum>sum&&small<middle){
			curSum-=small;
			small++;
			if(curSum==sum){
				PrintContinuousSequence(small,big);
				cout<<endl;
			}
		}
		big++;
		curSum+=big;
	}
}

void PrintContinuousSequence(int small,int big){
	for(int i=small;i<=big;++i)
		cout<<i<<"\t";
}

void main(){
	int sum=18;
	cout<<"The sum: "<< sum << "is the sum of the continue sequence:"<<endl;
	FindConttinuousSequence(18);
}