//算法原理：使用二分查找算法找到第一个K：二分查找法总是拿数组中间的数字和k做比较，如果中间的数字比k大，那么k只有可能出现在
//数组的前半部分，下一轮查找数组的前半段，如果中间的数字比k小，那么k只有可能出现在数组的后半段，，如果中间的数字和k相等，
//那么我们判断这个数字的前面一个是否是k如果不是则这个数字是第一个k，如果是，则说明第一个k在数组的前半段，下一轮需要在数组
//的前半段查找；查找最后一个k也是相同原理
#include <iostream>
using namespace std;

int GetFirstK(int* data, int length, int k, int start, int end){
	if(start>end)
		return -1;
	int middleIndex=(start+end)/2;
	int middleData=data[middleIndex];

	if(middleData==k){
		if((middleIndex>0&&data[middleIndex-1]!=k||middleIndex==0))
			return middleIndex;
		else
			end=middleIndex-1;
	}
	else if(middleData>k)
		end=middleIndex-1;
	else
		start=middleIndex+1;
	return GetFirstK(data,length,k,start,end);
}


int GetLastK(int* data, int length, int k, int start, int end){
	if(start>end)
		return -1;
	int middleIndex=(start+end)/2;
	int middleData=data[middleIndex];

	if(middleData==k){
		if((middleIndex<length-1&&data[middleIndex+1]!=k)||middleIndex==length-1){
			return middleIndex;
		}
		else
			start=middleIndex+1;
	}
	else if(middleData<k)
		start=middleIndex+1;
	else
		end=middleIndex-1;
	return GetLastK(data,length,k,start,end);
}

int GetNumberOfK(int* data, int length, int k){
	int number=0;
	if(data!=NULL&&length>0)
	{
		int first=GetFirstK(data,length,k,0,length-1);
		int last=GetLastK(data,length,k,0,length-1);
		if(first>-1&&last>-1)
			number=last-first+1;
	}
	return number;
}

void main(){
	int data[]={2,3,4,5,5,5,5,5,6,7,8,8,9,10};
	cout<<"the # of 5 in the data is :"<<GetNumberOfK(data,sizeof(data)/sizeof(int),5);
}