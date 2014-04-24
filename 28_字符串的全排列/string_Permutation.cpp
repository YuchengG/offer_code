#include <iostream>
using namespace std;
void Permutation(char* pStr, char* pBegin);
void Permutation(char *pStr){
	if(pStr==NULL)
		return;
	Permutation(pStr,pStr);
}

void Permutation(char* pStr,char* pBegin){
	if (*pBegin=='\0')
	{
		cout<<pStr<<endl;
	}
	else
	{
		for (char* pCh=pBegin; *pCh != '\0';++pCh)
		{
			char temp = *pCh;
 			*pCh = *pBegin;
			*pBegin=temp;
			Permutation(pStr,pBegin+1);//固定第一个字符，对后面字符串做相同操作
			temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
		}
	}
}


void main(){
	char testlist[]="abc";
	Permutation(testlist);
}