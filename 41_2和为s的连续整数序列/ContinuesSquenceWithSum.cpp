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
	//ͬǰһ��������࣬���small��big�����еĺ�С��s����ô��������big������s������small���ҵ���Ȼ������big�����������ظ�ǰ�沽�裬
	//��Ϊ���ܴ�����һ����ϵ����,����9 ���ҵ�2��3��4������bigΪ5��֮����ҵ�4��5ֱ��small����5��ֹͣѭ���õ�4��5.
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