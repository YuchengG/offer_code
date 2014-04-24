#include <list>
#include <vector>
#include <iostream>
#include <stack>
#include <time.h>
using namespace std;
//listΪstd�ı�׼,����stack���Ƚ������������������ͨ�������ƶ�̫�࣬

void Print_list_reversingly(list<int> ilist){
	stack<int> nodes;

	for (list<int>::iterator iter=ilist.begin();iter!=ilist.end();++iter)
	{
		nodes.push(*iter);
	}
	while(!nodes.empty()){
		int i=nodes.top();
		//cout<<i<<" ";
		nodes.pop();
	}
}
// �ڶ������������õݹ飬��Ϊ�ݹ�ʵ���Ͼ��Ǹ�ջ�ṹ�������и������ǵ�����Ƚϳ���ʱ�򣬺������õĲ㼶�϶࣬���׵��º���
// ����ջ���,5000������ֱ�ӻ�������ò���ʱ��
void Print_list_reversingly_recursively(list<int> ilist){

	if(!ilist.empty()){
		int i=ilist.front();
		ilist.pop_front();
		if (!ilist.empty())
		{
			Print_list_reversingly_recursively(ilist);
		}
		//cout<<i<<" ";
	}
}

void main(){
	list<int> ilist;
	/*ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);
	ilist.push_back(4);
	ilist.push_back(5);
	ilist.push_back(6);*/
	for(int i=0;i<1000;i++)
		ilist.push_back(i);
	clock_t start,finish;
	cout<< "����ջ��"<<endl;
	start=clock();
	Print_list_reversingly(ilist);
	finish=clock();
	cout<< "ʱ������:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
	cout<< "���õݹ�"<<endl;
	start=clock();
	Print_list_reversingly_recursively(ilist);
	finish=clock();
	cout<< "ʱ������:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
}