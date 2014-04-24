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
	int rootValue=startPreorder[0];//ǰ���һ��Ϊ�����
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=rootValue;
	root->m_pLeft=root->m_pRight=NULL;
	//���ֻ��һ�����
	if (startPreorder==endPreorder)
	{
		if (startInorder==endInoder&& *startPreorder==*startInorder)
		{
			return root;
		}
		else
			throw std::exception("Invalid input");
	}
	//���������Ѱ�ҵ����ڵ��ֵ
	int* rootInoder=startInorder;
	while(rootInoder<=endInoder&&*rootInoder!=rootValue)
		++rootInoder;
	if(rootInoder==endInoder&&*rootInoder!=rootValue)
		throw std::exception("Invalid input.");
	int leftLenght=rootInoder-startInorder;//����root������Ϊ������
	int * leftPreorderEnd=startPreorder+leftLenght;//ȷ��ǰ����������Χ
	if (leftLenght>0)
	{
		root->m_pLeft=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInoder-1);
	}
	if(leftLenght<endPreorder-startPreorder){//����ǰ���г���root������������⻹�����������
		root->m_pRight=ConstructCore(leftPreorderEnd+1,endPreorder,rootInoder+1,endInoder);
	}
	return root;
}

// ====================���Դ���====================
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

// ��ͨ������
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

// ���н�㶼û�����ӽ��
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

// ���н�㶼û�����ӽ��
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

// ����ֻ��һ�����
void Test4()
{
	const int length = 1;
	int preorder[length] = {1};
	int inorder[length] = {1};

	Test("Test4", preorder, inorder, length);
}

// ��ȫ������
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

// �����ָ��
void Test6()
{
	Test("Test6", NULL, NULL, 0);
}

// ������������в�ƥ��
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

