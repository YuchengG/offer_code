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

char* ReverseSentence(char *pData){
	if(pData==NULL)
		return NULL;
	char *pBegin=pData;
	char *pEnd=pData;
	while(*pEnd!='\0')
		pEnd++;
	pEnd--;
	reverse(pBegin,pEnd);

	pBegin=pEnd=pData;
	while(*pBegin!='\0'){
		if(*pBegin==' '){
			pBegin++;
			pEnd++;
		}
		else if(*pEnd=='\0'||*pEnd==' '){
			reverse(pBegin,--pEnd);
			pBegin=++pEnd;
		}
		else{
			pEnd++;
		}
	}
	return pData;
}
void print_str(char *pData){
	while(*pData!='\0'){
		cout<<*pData;
		pData++;
	}
}

void main(){
	char str[]="I am a student!";
	cout<<"the reverse of the str is :"<<endl;
	print_str(ReverseSentence(str));
}