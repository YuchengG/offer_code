#include <iostream>
using namespace std;
/************************************************************************/
/* �ӵ�һ�е����һ������ʼ�����С��number�������ƣ���column--������������
�ƶ���row++*/
/************************************************************************/
bool Find(int **matrix,int rows,int columns,int number){
	int row=0,column=columns-1;
	bool found=false;
	if(matrix!=NULL&&rows>0&&columns>0){
	while(row<rows&&column>=0){
		if(number<*(*(matrix+row)+column)){
			column--;
		}
		else if (number>*(*(matrix+row)+column))
		{
			row++;
		}
		else{
			found=true;
			break;
		}
	}
	}
	return found;
}

void main(){
	int **a;
	a=new int *[4];
	for (int i=0;i<4;i++)
	{
		a[i]=new int[4];
		for (int j=0;j<4;j++)
		{
			a[i][j]=i*4+j;
		}
	}
	
	/*for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			a[i][j]=i*4+j;
		}
	}*/
	int b=7;
	cout<< "is "<<b<<" in a ?:"<< boolalpha << Find(a,4,4,7);
}