#include <iostream>
#include "../Utilities/BinaryTree.h"

void MirrorRecursively(BinaryTreeNode *pNode){
	if(pNode==NULL)
		return;
	if(pNode->m_pLeft==NULL&&pNode->m_pRight==NULL)
		return;
	BinaryTreeNode* ptemp=pNode->m_pLeft;
	pNode->m_pLeft=pNode->m_pRight;
	pNode->m_pRight=ptemp;
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	if (pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}

int main(){
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
	PrintTree(pNodeA1);
	MirrorRecursively(pNodeA1);
	PrintTree(pNodeA1);
}