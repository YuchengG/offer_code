#include <iostream>
using namespace std;
bool VerifySquenceOfBST(int sequence[], int length){
	if (sequence==NULL||length<=0)
		return false;
	int root=sequence[length-1];
	int i=0;
	for(;i<length-1;i++){
		if (sequence[i]>root)
			break;
	}
	int j=i;
	for (;j<length-1;j++)
	{
		if (sequence[j]<root)
		{
			return false;
		}
	}
	bool left=true;
	if(i>0)
		left=VerifySquenceOfBST(sequence,i);
	bool right=true;
	if(i<length-1)
		right=VerifySquenceOfBST(sequence+i,length-1-i);
	return (left&&right);
}
//ÅÐ¶ÏÊÇ·ñÎª¶þ²æËÑË÷Ê÷µÄÇ°Ðò
bool VerifySquenceOfBST_preorder(int sequence[],int length){
	if(sequence==NULL||length<=0)
		return false;
	int root=sequence[0];
	int i=1;
	for(;i<length;i++){
		if(sequence[i]>root)
			break;
	}
	int j=i;
	for (;j<length;j++)
	{
		if(sequence[j]<root)
			return false;
	}
	bool left=true;
	bool right=true;
	if(i>1)
		left=VerifySquenceOfBST_preorder(sequence+1,i);
	if(j<length-1)
		right=VerifySquenceOfBST_preorder(sequence+i,length-i);
	return (left&&right);

}

void main(){
	int sequence[]={5,7,6,9,11,10,8};
	cout<<"the list:5 7 6 9 11 10 8 is some BST's postorder?"<<boolalpha<<VerifySquenceOfBST(sequence,sizeof(sequence)/sizeof(int))<<endl;
	int sequence2[]={5,4,3,7,6,8};
	cout<<"the list:5,4,3,7,6,8 is some BST's preorder?"<<boolalpha<<VerifySquenceOfBST_preorder(sequence2,sizeof(sequence2)/sizeof(int))<<endl;
	int sequence3[]={10,11,2};
	cout<<"the list:10,11,2 is some BST's preorder?"<<boolalpha<<VerifySquenceOfBST_preorder(sequence3,sizeof(sequence3)/sizeof(int));
}