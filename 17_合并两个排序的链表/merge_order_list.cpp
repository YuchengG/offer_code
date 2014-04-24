#include <iostream>
#include "../Utilities/List.h"
using namespace std;
//这个题目的方法很简单，有两种实现形式：递归和非递归
ListNode* merge_order_list_rec(ListNode* pHead1,ListNode*pHead2){
	if(pHead1==NULL)
		return pHead2;
	if(pHead2==NULL)
		return pHead1;
	ListNode *pMergeHead=NULL;
	if(pHead1->m_nValue<pHead2->m_nValue){
		pMergeHead=pHead1;
		pMergeHead->m_pNext=merge_order_list_rec(pHead1->m_pNext,pHead2);
	}
	else{
		pMergeHead=pHead2;
		pMergeHead->m_pNext=merge_order_list_rec(pHead1,pHead2->m_pNext);
	}
	return pMergeHead;
}

ListNode* merge_order_list(ListNode* pHead1,ListNode* pHead2){
	if(pHead1==NULL)
		return pHead2;
	if(pHead2==NULL)
		return pHead1;
	ListNode* pNode1=pHead1,*pNode2=pHead2;
	ListNode* pMergeHead=NULL;
	if(pHead1->m_nValue<pHead2->m_nValue){
		pMergeHead=pHead1;
		pNode1=pNode1->m_pNext;
	}
	else{
		pMergeHead=pHead2;
		pNode2=pNode2->m_pNext;
	}
	ListNode* pMergeNode=pMergeHead;
	while(pNode1!=NULL&&pNode2!=NULL){
		if(pNode1->m_nValue<pNode2->m_nValue){
			pMergeNode->m_pNext=pNode1;
			pNode1=pNode1->m_pNext;
		}
		else{
			pMergeNode->m_pNext=pNode2;
			pNode2=pNode2->m_pNext;
		}
		pMergeNode=pMergeNode->m_pNext;
	}
	if(pNode1!=NULL){
		while(pNode1!=NULL){
		pMergeNode->m_pNext=pNode1;
		pNode1=pNode1->m_pNext;
		pMergeNode=pMergeNode->m_pNext;
		}
	}
	if(pNode2!=NULL){
		while(pNode2!=NULL){
		pMergeNode->m_pNext=pNode2;
		pNode2=pNode2->m_pNext;
		pMergeNode=pMergeNode->m_pNext;
		}
	}
	return pMergeHead;
}

int main(){
	ListNode* p1Node1 = CreateListNode(1);
	ListNode* p1Node2 = CreateListNode(2);
	ListNode* p1Node3 = CreateListNode(3);
	ListNode* p1Node4 = CreateListNode(4);
	ListNode* p1Node5 = CreateListNode(5);

	ConnectListNodes(p1Node1, p1Node2);
	ConnectListNodes(p1Node2, p1Node3);
	ConnectListNodes(p1Node3, p1Node4);
	ConnectListNodes(p1Node4, p1Node5);

	ListNode* p2Node1 = CreateListNode(0);
	ListNode* p2Node2 = CreateListNode(3);
	ListNode* p2Node3 = CreateListNode(7);
	ListNode* p2Node4 = CreateListNode(9);
	ListNode* p2Node5 = CreateListNode(10);
	

	ConnectListNodes(p2Node1, p2Node2);
	ConnectListNodes(p2Node2, p2Node3);
	ConnectListNodes(p2Node3, p2Node4);
	ConnectListNodes(p2Node4, p2Node5);
	PrintList(p2Node1);

	//PrintList(merge_order_list_rec(p1Node1,p2Node1));
	PrintList(merge_order_list(p1Node1,p2Node1));
}