#include <iostream>
using namespace std;
//length为字符数组的总长度
void replace_blank(char string[],int length){
	if(string==NULL||length<=0)
		return;
	int originallength=0;
	int numberofblank=0;
	int i=0;
	while(string[i]!='\0'){
		++originallength;
		if (string[i]==' ')
		{
			++numberofblank;
		}
		i++;
	}
	int newlength=originallength+2*numberofblank;
	if(newlength>length)
		return;
	int indexoriginal=originallength;
	int indexnew=newlength;
	while (indexoriginal>0&&indexnew>indexoriginal)
	{
		if(string[indexoriginal]==' '){
			string[indexnew--]='0';
			string[indexnew--]='2';
			string[indexnew--]='%';
		}
		else
			string[indexnew--]=string[indexoriginal];
		--indexoriginal;
	}
}

void main(){
	const int length=100;
	char string[length]="hello world everyone!";
	replace_blank(string,length);
	int i=0;
	while(string[i]!='\0'){
		cout<<string[i];
		i++;
	}
}