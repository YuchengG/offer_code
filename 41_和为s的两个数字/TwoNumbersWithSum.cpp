#include <iostream>
using namespace std;
bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int *num2){
	bool found=false;
	if(length<1||num1==NULL||num2==NULL)
		return found;
	int ahead=length-1;
	int behind=0;
	while(ahead>behind){
		long long curSum=data[ahead]+data[behind];
		if(curSum==sum){
			*num1=data[behind];
			*num2=data[ahead];
			found= true;
			break;
		}
		else if(curSum>sum){
			ahead--;
		}
		else
			behind++;
	}

	return found;
}

void main(){
	int data[]={1,2,4,7,11,15};
	int num1,num2;
	if(FindNumbersWithSum(data,sizeof(data)/sizeof(int),15,&num1,&num2)){
		cout<<"The sum of two num :"<<num1<<" and "<<num2<<" is 15"<<endl;
	}
}