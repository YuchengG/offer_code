#include <list>
#include <vector>
#include <iostream>
#include <stack>
#include <time.h>
using namespace std;
//list为std的标准,利用stack的先进后出进行输出，而如果通过链表移动太多，

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
// 第二种做法，利用递归，因为递归实际上就是个栈结构，但是有个坏处是当链表比较长的时候，函数调用的层级较多，容易导致函数
// 调用栈溢出,5000个数就直接会溢出，得不到时间
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
	cout<< "利用栈："<<endl;
	start=clock();
	Print_list_reversingly(ilist);
	finish=clock();
	cout<< "时间消耗:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
	cout<< "利用递归"<<endl;
	start=clock();
	Print_list_reversingly_recursively(ilist);
	finish=clock();
	cout<< "时间消耗:"<<(double)(finish-start)/CLOCKS_PER_SEC<<endl;
}