#include "..\Utilities\BinaryTree.h"
#include <exception>
#include <iostream>
using namespace std;

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,int* startInorder, int* endInoder);
BinaryTreeNode* Construct(int* preorder,int* inorder, int length){
	if (preorder==NULL||inorder==NULL||length<=0)
	{
		return NULL;
	}
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,int* startInorder, int* endInoder){
	int rootValue=startPreorder[0];//前序第一个为根结点
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=rootValue;
	root->m_pLeft=root->m_pRight=NULL;
	//如果只有一个结点
	if (startPreorder==endPreorder)
	{
		if (startInorder==endInoder&& *startPreorder==*startInorder)
		{
			return root;
		}
		else
			throw std::exception("Invalid input");
	}
	//在终须遍历寻找到根节点的值
	int* rootInoder=startInorder;
	while(rootInoder<=endInoder&&*rootInoder!=rootValue)
		++rootInoder;
	if(rootInoder==endInoder&&*rootInoder!=rootValue)
		throw std::exception("Invalid input.");
	int leftLenght=rootInoder-startInorder;//中序root结点左边为左子树
	int * leftPreorderEnd=startPreorder+leftLenght;//确定前序左子树范围
	if (leftLenght>0)
	{
		root->m_pLeft=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInoder-1);
	}
	if(leftLenght<endPreorder-startPreorder){//表明前序中除了root和左子树结点外还有右子树结点
		root->m_pRight=ConstructCore(leftPreorderEnd+1,endPreorder,rootInoder+1,endInoder);
	}
	return root;
}

// ====================测试代码====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if(testName != NULL)
		//printf("%s begins:\n", testName);
		cout<<testName;
	//printf("The preorder sequence is: ");
	cout<<"The preorder sequence is: ";
	for(int i = 0; i < length; ++ i)
		//printf("%d ", preorder[i]);
		cout<<preorder[i];
	//printf("\n");
	cout<<endl;

	//printf("The inorder sequence is: ");
	cout<<"The inorder sequence is: ";
	for(int i = 0; i < length; ++ i)
		//printf("%d ", inorder[i]);
		cout<<inorder[i];
	//printf("\n");
	cout<<endl;

	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch(std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

	Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = {1, 2, 3, 4, 5};
	int inorder[length] = {5, 4, 3, 2, 1};

	Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = {1, 2, 3, 4, 5};
	int inorder[length] = {1, 2, 3, 4, 5};

	Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
	const int length = 1;
	int preorder[length] = {1};
	int inorder[length] = {1};

	Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
	int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

	Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
	Test("Test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void Test7()
{
	const int length = 7;
	int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
	int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

	Test("Test7: for unmatched input", preorder, inorder, length);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}

