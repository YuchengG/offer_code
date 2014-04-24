#include <iostream>
using namespace std;

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void PrintMatrixClockwisely(int** number, int columns, int rows){
	if(number==NULL||columns<=0||rows<=0)
		return;
	int start=0;
	while(columns>start*2&&rows>start*2){
		PrintMatrixInCircle(number,columns,rows,start);
		start++;
	}
}

// 打印一圈分为四部分：第一步从左到右，第二部从上到下打印一列，第三部从右到左打印一行
// 第四部分从下到上打印一列。重点是：打印一环除了第一步之外其他可能不存在换句话说，其他存在需
// 满足一定的条件，第二步存在的条件是终止行号必须大于起始行号，第三部条件是至少有两行两列，即终止行号大于
// 起始行号外，还需要终止列号大于起始列号。第四步必须至少有三航两列，即终止行号比起始行号至少大2
// 同时终止列号大于起始列号
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start){
	//终止列号，终止行号
	int endX=columns-1-start;
	int endY=rows-1-start;

	//第一步
	for(int i=start;i<=endX;i++){
		int number=numbers[start][i];
		cout<< number<<" ";
	}
	//第二步
	if(start<endY){
		for (int i=start+1;i<=endY;i++)
		{
			int number=numbers[i][endX];
			cout<<number<<" ";
		}
	}
	//第三步
	if(start<endX&&start<endY){
		for (int i=endX-1;i>=start;--i)
		{
			int number=numbers[endY][i];
			cout<<number<<" ";
		}
	}
	//第四步
	if(start<endX&&start<endY-1){
		for (int i=endY-1;i>=start+1;--i)
		{
			int number=numbers[i][start];
			cout<<number<<" ";
		}
	}
	cout<<endl;
}

void main(){
	int **array=new int *[4];
	for(int i = 0; i < 4; ++i)
	{
		array[i] = new int[4];
		for(int j = 0; j < 4; ++j)
		{
			array[i][j] = i * 4 + j + 1;
		}
	}
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}

	PrintMatrixClockwisely(array,4,4);

}