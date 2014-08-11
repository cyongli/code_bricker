#include<iostream>
#include<string>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode* next;
}ListNode;

class Solution {
public:
     void reverse(ListNode* head) {
    	if(head==NULL || head->next==NULL) return;
 		ListNode*curr,*next;
		curr = head->next;
		head->next = NULL;
		while(curr != NULL){
			next = curr->next;
			curr->next = head->next;
			head->next = curr;
			curr = next;
		}	
    }
    
    void merge(ListNode* p1, ListNode* p2){
        ListNode* n1,*n2;
        while(p1->next!=NULL){
            n1 = p1->next;
            n2 = p2->next;
            
            p1->next = p2;
            p2->next = n1;
            
            p1 = n1;
            p2 = n2;
        }
        p1->next = p2;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL ) return;
    	ListNode* fast = head;
    	ListNode* slow = head;
    	ListNode* pre = NULL;
    	while(fast!=NULL && fast->next!=NULL){
    	    fast=fast->next->next;
    	    pre = slow;
    	    slow=slow->next;
    	}
    	reverse(pre);
    	slow = pre->next;
    	pre->next = NULL;
    	merge(head,slow);
    }
};

int main(int argc, char* argv[]){
	FILE* fi = fopen(argv[1],"r");
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	for(int i=0;i<stoi(argv[2]);i++){
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		fscanf(fi,"%d\n",&(node->val));
		node->next = head->next;
		head->next = node;
	}	
	fclose(fi);
	ListNode* pos = head->next;
	while(pos!=NULL){
		cout << pos->val << endl;
		pos = pos->next;
	}
	cout << "after reverse" << endl;
	Solution sol;
	sol.reorderList(head->next);
	pos = head->next;
	while(pos!=NULL){
		cout << pos->val << endl;
		pos = pos->next;
	}
	return 0;
}
