/************************************************************************/
/* ��ά���飬Ԫ�ش������������ӣ����ϵ����������ӣ���β���Ԫ���Ƿ��ڸ�
��ά�����ڣ���Ϊ���Ͼ������Ԫ���Ƿ��������ڣ���һ�ַ������ڽ�ָoffer����
���ᵽ*/
/************************************************************************/
#include <iostream>
using namespace std;
bool Find(int* martix, int rows, int columns, int number){
	bool found=false;
	if(martix!=NULL&&rows>0&&columns>0){
		int row=0;
		int column=columns-1;
		while(row<rows&&columns>=0){
			if(martix[row*rows+column]==number){
				found=true;
				break;
			}
			else if (martix[row*rows+column]>number)
			{
				column--;
			}
			else{
				row++;
			}
		}
	}
	return found;
}

void main(){
	int a[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int b=7;
	cout<< "is "<<b<<" in a ?:"<< boolalpha << Find((int *)a,4,4,7);
}