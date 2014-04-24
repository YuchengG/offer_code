#include "StackWithMin.h"
#include <iostream>
using namespace std;

void main(){
	StackWithMin<int> stack_min;
	stack_min.push(2);
	stack_min.push(3);
	stack_min.push(1);
	stack_min.push(7);
	stack_min.push(4);
	cout<<"In 2->3->1->7->4, the min is "<<stack_min.min()<<endl;
	stack_min.pop();
	cout<<"In 2->3->1->7, the min is "<<stack_min.min()<<endl;
	stack_min.pop();
	cout<<"In 2->3->1, the min is "<<stack_min.min()<<endl;
	stack_min.pop();
	cout<<"In 2->3, the min is "<<stack_min.min()<<endl;

}