#include<iostream>
#include<cstdlib>
#include<vector>
#include "minHeap.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static bool prior(ListNode *r1, ListNode *r2){
	return r1->val < r2->val;
    }
};

class Comp{
public:
    static bool prior(ListNode *r1, ListNode *r2){
	return r1->val < r2->val;
    }
};

class Solution {
private:
    minHeap<ListNode*,Comp> *heap;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists){
	ListNode head(0),*p=&head,*q;
	int len = lists.size();
	heap = new minHeap<ListNode*,Comp>(len);
	for(int i=0;i<len;i++){
	    if(lists[i]!=NULL){
		heap->insert(lists[i]);
		//cout << "size:" << heap->size() << endl;
	    }
	}
	//cout << "size:" << heap->size() << endl;
	while(heap->empty()!=true){
	    q = heap->removeFirst();
	    //cout << "size:" << heap->size() << endl;
	    if(q->next != NULL){
		heap->insert(q->next);
		//cout << "size:" << heap->size() << endl;
	    }
	    p->next = q;
	    p=p->next;
	}
	return head.next;
    }
};


int main(int argc, char * argv[]){
    vector<ListNode*> lists;
    ListNode* head1=(ListNode*)malloc(sizeof(ListNode));
    head1->next = NULL;
    head1->val = 1;
    for(int i=3;i>=2;--i){
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->val = i;
	node->next = head1->next;
	head1->next = node;
    }

    ListNode* head2=(ListNode*)malloc(sizeof(ListNode));
    head2->next = NULL;
    head2->val = 4;
    for(int i=7;i>=5;--i){
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->val = i;
	node->next = head2->next;
	head2->next = node;
    }
    
    lists.push_back(head1);
    lists.push_back(head2);

    Solution sol;
    ListNode*head = sol.mergeKLists(lists);
    
    ListNode*p = head;
    while(p!=NULL){
	cout << p->val << endl;
	p = p->next;
    }
    
    return 0;
}
