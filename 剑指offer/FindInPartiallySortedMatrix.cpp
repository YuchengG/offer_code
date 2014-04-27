/************************************************************************/
/* 二维数组，元素从左到右依次增加，从上到下依次增加，如何查找元素是否在该
二维数组内，即为杨氏矩阵查找元素是否在数组内，第一种方法，在剑指offer上面
有提到*/
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