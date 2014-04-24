#include <iostream>
#include "../Utilities/List.h"
ListNode * reverse_list(ListNode* pHead){
	ListNode * pReverseHead=NULL;
	ListNode * pNode=pHead;
	ListNode * pPrev=NULL;

	if(pHead==NULL)
		return NULL;
	if(pHead->m_pNext==NULL){
		return pHead;
	}
	else{
		
		while(pNode!=NULL){
			ListNode* pNext=pNode->m_pNext;
			if(pNext==NULL)
				pReverseHead=pNode;
			pNode->m_pNext=pPrev;
			pPrev=pNode;
			pNode=pNext;
		}
	}
	return pReverseHead;
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
	PrintList(pNode1);
	PrintList(reverse_list(pNode1));
	
}