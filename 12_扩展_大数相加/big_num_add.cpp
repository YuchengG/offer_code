
#include <stdio.h>
#include <stdlib.h>
#define NUM_LEN 100

int add_str(char * pch1,char * pch2 , char * chResult){
	chResult[NUM_LEN]='\0';
	int idx=NUM_LEN-1;
	//找到各自数的最低位
	char *pEnd1=pch1,*pEnd2=pch2;
	for(;*pEnd1!='\0';pEnd1++);
	for(;*pEnd2!='\0';pEnd2++);
	pEnd1--;
	pEnd2--;

	short flag=0;     //是否有进位
	for(;(pEnd1!=pch1-1) || (pEnd2!=pch2-1);){//pEnd1==pch1-1的时候表明在第二位（由进制高到低），存在任意一个数到第二位后，循环终止
		short b1=0;
		if(pEnd1!=pch1-1){//表明是pch1没有移动到第二位
			b1= (short)(*pEnd1)-(short)'0'; // '0' -> 0
			pEnd1--;//往高进制位移动一位
		}
		short b2=0;
		if(pEnd2!=pch2-1){
			b2= (short)(*pEnd2)-(short)'0'; // '0' -> 0
			pEnd2--;//得到当前位的数字并且往高进制移动一位
		}
		short sResult = b1+b2+flag;
		flag=0;
		if(sResult>9){flag=sResult/10;sResult %=10;}//得到进位和当前位置上的数字
		chResult[idx--] =(char)( sResult+(short)'0');//将数字变为对应的字符存入字符串
	}
	if(flag)chResult[idx--]=flag+(short)'0';
	return idx+1;
}

int main()
{
	char ch1[NUM_LEN],ch2[NUM_LEN],chResult[NUM_LEN+1];
	printf("Num1:");
	scanf("%s",ch1);

	printf("\nNum2:");
	scanf("%s",ch2);

	printf("\nNum1=%s",ch1);
	printf("\nNum2=%s",ch2);

	int idx=add_str(ch1,ch2,chResult);
	printf("\n结果:%s",(char*)chResult+idx);

	return 0;
}