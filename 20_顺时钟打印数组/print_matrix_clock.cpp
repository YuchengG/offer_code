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

// ��ӡһȦ��Ϊ�Ĳ��֣���һ�������ң��ڶ������ϵ��´�ӡһ�У����������ҵ����ӡһ��
// ���Ĳ��ִ��µ��ϴ�ӡһ�С��ص��ǣ���ӡһ�����˵�һ��֮���������ܲ����ڻ��仰˵������������
// ����һ�����������ڶ������ڵ���������ֹ�кű��������ʼ�кţ��������������������������У�����ֹ�кŴ���
// ��ʼ�к��⣬����Ҫ��ֹ�кŴ�����ʼ�кš����Ĳ������������������У�����ֹ�кű���ʼ�к����ٴ�2
// ͬʱ��ֹ�кŴ�����ʼ�к�
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start){
	//��ֹ�кţ���ֹ�к�
	int endX=columns-1-start;
	int endY=rows-1-start;

	//��һ��
	for(int i=start;i<=endX;i++){
		int number=numbers[start][i];
		cout<< number<<" ";
	}
	//�ڶ���
	if(start<endY){
		for (int i=start+1;i<=endY;i++)
		{
			int number=numbers[i][endX];
			cout<<number<<" ";
		}
	}
	//������
	if(start<endX&&start<endY){
		for (int i=endX-1;i>=start;--i)
		{
			int number=numbers[endY][i];
			cout<<number<<" ";
		}
	}
	//���Ĳ�
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