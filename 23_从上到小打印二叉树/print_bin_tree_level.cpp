#include "../Utilities/BinaryTree.h"
#include <iostream>
#include <deque>
using namespace std;
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
	if(!pTreeRoot)
		return;
	std::deque<BinaryTreeNode *> dequeTreeNode;
	dequeTreeNode.push_back(pTreeRoot);
	while(dequeTreeNode.size()){
		BinaryTreeNode *pNode=dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout<<pNode->m_nValue<<" ";
		if(pNode->m_pLeft){
			dequeTreeNode.push_back(pNode->m_pLeft);
		}
		if(pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight); 
	}
}


void main(){
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);
	PrintFromTopToBottom(pNodeA1);
}