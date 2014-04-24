#include <iostream>
#include <exception>
using namespace std;

//����ָ��ֱ�ָ������ͷβ��ͷ��ָ������ƶ�֪��ָ��ż����β��ָ����ǰ�ƶ�ֱ��ָ��������������ͷ��ָ��С��β��ָ��
//������£��������ݼ��ɽ��������ű�֤������ż��֮ǰ

void record_array(int *pData, unsigned int length){
	if(pData==NULL||length<=0)
		throw exception("Invaild array to reorder");
	int *pBegin=pData;
	int *pEnd=pData+length-1;
	while(pBegin<pEnd){
		//����ƶ���ֱ��ָ��ż��
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
//һ������չ�Եĺ����Ǵ���һ������ָ�룬����ָ���жϹ����縺���ŵ��Ǹ�֮�󣬱�3�������ŵ����ܱ�3�����ĺ���
void record_array_extent(int *pData, unsigned int length,bool (*func)(int)){
	if(pData==NULL||length<=0)
		throw exception("Invaild array to reorder");
	int *pBegin=pData;
	int *pEnd=pData+length-1;
	while(pBegin<pEnd){
		//����ƶ���ֱ��ָ��ż��
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
//����ֻ������жϺ��������¹���������ú���ָ��ķ��������ӳ������չ��
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