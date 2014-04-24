#include <iostream>
#include <exception>
using namespace std;
int mininorder(int *number,int index1,int index2);
int min(int * numbers, int length){
	if (numbers ==NULL||length<=0)
	{
		throw exception("Invaild parameters");
	}
	int index1=0;
	int index2=length-1;
	int indexmid=index1;
	while (numbers[index1]>=numbers[index2])
	{
		if (index2-index1 ==1)
		{
			indexmid=index2;
			break;
		}
		indexmid=(index1+index2)/2;
		if(numbers[index1]==numbers[index2]&&numbers[index1]==numbers[indexmid])
			return mininorder(numbers,index1,index2);
		if(numbers[indexmid]>=numbers[index1])
			index1=indexmid;
		else if(numbers[indexmid]<=numbers[index2])
			index2=indexmid;
	}
	return numbers[indexmid];
}

int mininorder(int * numbers,int index1,int index2){
	int result=numbers[index1];
	for (int i=index1+1;i<=index2;i++)
	{
		if(result>numbers[i]){
			result=numbers[i];
		}
		return result;
	}
}

int main(){
	int numbers[]={3,4,5,1,2};
	int length=sizeof(numbers)/sizeof(int);
	cout<<"In [3,4,5,1,2], the min is :"<<min(numbers,length)<<endl;
	int numbers2[]={1,0,1,1,1};
	int length2=sizeof(numbers2)/sizeof(int);
	cout<<"In [1,0,1,1,1], the min is :"<<min(numbers2,length2)<<endl;


}