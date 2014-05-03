#include <iostream>
using namespace std;
unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2){
	if(data==NULL || length<2)
		return;
	int resultExclusiveOR=0;
	for(int i=0;i<length;i++)
		resultExclusiveOR ^=data[i];//�����Ϊ0����Ϊ��������ͬ������
	unsigned int indexOf1=FindFirstBitIs1(resultExclusiveOR);//�ҵ�Ϊ1����λ������������ͬ�������ڴ�λһ����һ��Ϊ0����һ��Ϊ1
	*num1=*num2=0;
	for(int j=0;j<length;j++){
		if(IsBit1(data[j],indexOf1))//��Ϊ����������
			*num1 ^=data[j];
		else
			*num2 ^=data[j];
	}
}
unsigned int FindFirstBitIs1(int num){
	int indexBit=0;
	while(((num&1)==0)&&(indexBit<8*sizeof(int)))//8*sizeof(int)��ʾ���͵�λ��32
	{
		num=num>>1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit){
	num=num>>indexBit;
	return (num&1);//�ж�indexBitλ�Ƿ�Ϊ1
}

void main(){
	int data[]={2,4,3,6,3,2,5,5};
	int num1;
	int num2;
	FindNumsAppearOnce(data,sizeof(data)/sizeof(int),&num1,&num2);
	cout<<"the 2 different nums is :"<<num1<<" and "<<num2<<endl;
}