#include <iostream>
using namespace std;
void reverse(char *pBegin, char *pEnd){
	if(pBegin==NULL||pEnd==NULL)
		return;
	while(pBegin<pEnd){
		char temp=*pBegin;
		*pBegin=*pEnd;
		*pEnd=temp;
		pBegin++,pEnd--;
	}
}

char* LeftRotateString(char* pStr, int n){
	if(pStr!=NULL){
		int nLength=static_cast<int>(strlen(pStr));
		if(nLength>0&&n>0&&n<nLength){
			char* pFirstStart=pStr;
			char* pFirstEnd=pStr+n-1;
			char* pSecondStart=pStr+n;
			char* pSecondEnd=pStr+nLength-1;


			reverse(pFirstStart,pFirstEnd);
			reverse(pSecondStart,pSecondEnd);
			reverse(pFirstStart,pSecondEnd);
		}
	}
	return pStr;
}
void print_str(char *pData){
	while(*pData!='\0'){
		cout<<*pData;
		pData++;
	}
}

void main(){
	char data[]="abcdefg";
	int n=2;
	LeftRotateString(data,n);
	print_str(data);
}