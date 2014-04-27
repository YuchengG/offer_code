#include <iostream>
using namespace std;

char FirstNotRepeatingChar(char *pString){
	if(pString==NULL)
		return '\0';
	const int tablesize=256;
	unsigned int hashTable[tablesize];
	for (unsigned int index=0;index<tablesize;index++)
	{
		hashTable[index]=0;
	}
	char *pHashKey=pString;
	while(*(pHashKey)!='\0')
		hashTable[*(pHashKey++)]++;

	pHashKey=pString;
	while(*pHashKey!='\0'){
		if(hashTable[*pHashKey]==1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}


void main(){
	char string[]="sadjpoqwjalshdjrfwejoasdqweasdg";
	cout<<"the first not repeat is "<<FirstNotRepeatingChar(string);
}