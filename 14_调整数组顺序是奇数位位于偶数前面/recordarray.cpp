#include <iostream>
#include <exception>
using namespace std;

//两个指针分别指向链表头尾，头部指针向后移动知道指向偶数，尾部指针向前移动直到指向奇数，在满足头部指针小于尾部指针
//的情况下，交换内容即可将数组重排保证奇数在偶数之前

void record_array(int *pData, unsigned int length){
	if(pData==NULL||length<=0)
		throw exception("Invaild array to reorder");
	int *pBegin=pData;
	int *pEnd=pData+length-1;
	while(pBegin<pEnd){
		//向后移动，直到指向偶数
		while(pBegin<pEnd&&(*pBegin & 0x1)!=0)
			pBegin++;
		while(pBegin<pEnd&&(*pEnd & 0x1)==0)
			pEnd--;
		if(pBegin<pEnd){
			int temp;
			temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}
//一个可扩展性的函数是传入一个函数指针，用来指定判断规则如负数排到非负之后，被3整除的排到不能被3整除的后面
void record_array_extent(int *pData, unsigned int length,bool (*func)(int)){
	if(pData==NULL||length<=0)
		throw exception("Invaild array to reorder");
	int *pBegin=pData;
	int *pEnd=pData+length-1;
	while(pBegin<pEnd){
		//向后移动，直到指向偶数
		while(pBegin<pEnd&&(*pBegin & 0x1)!=0)
			pBegin++;
		while(pBegin<pEnd&&(*pEnd & 0x1)==0)
			pEnd--;
		if(pBegin<pEnd){
			int temp;
			temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}
//我们只需更改判断函数来更新规则，这里采用函数指针的方法来增加程序的扩展性
bool isEven(int n){
	return (n&1)==0;
}
void main(){
	int ilist[]={1,2,3,4,5,6,7};
	//record_array(ilist,sizeof(ilist)/sizeof(int));
	bool (*func)(int);
	func=isEven;
	record_array_extent(ilist,sizeof(ilist)/sizeof(int),func);
	for(int i=0;i<sizeof(ilist)/sizeof(int);i++)
		cout<<ilist[i];
}