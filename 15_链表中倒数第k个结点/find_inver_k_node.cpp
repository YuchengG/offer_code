/************************************************************************/
/* 寻找一个链表的倒数第k个节点，一次遍历链表的方法：新建两个指针pAhead,pBehind,
在前k-1次，pAhead++而pBehind不变，k后，pAhead++时，pBehind++，当pAhead到链表
尾部的时候，pBehind即为倒数第k个结点*/
/************************************************************************/
#include <iostream>
#include "../Utilities/List.h"
using namespace std;
ListNode* find_inver_k_node(ListNode* pListHead, unsigned int k){
	if(pListHead==NULL||k==0)
		return NULL;
	ListNode* pAhead=pListHead,*pBehind=pListHead;
	for(unsigned  int i=1;i<k;i++){
		if(pAhead->m_pNext!=NULL)
			pAhead=pAhead->m_pNext;
	}
	while(pAhead->m_pNext!=NULL){
		pAhead=pAhead->m_pNext;
		pBehind=pBehind->m_pNext;
	}
	return pBehind;
}

int main(){
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ListNode* p_k=find_inver_k_node(pNode1,5);
	if(p_k!=NULL){
		cout<<"倒数第三个节点内容是"<<p_k->m_nValue<<endl;
		return 0;
	}
	return -1;

}