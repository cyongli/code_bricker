#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(NULL==l1) return l2;
        if(NULL==l2) return l2;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int tmp,carry=0;
        ListNode head(0),*p=&head;
        head.next = NULL;
        while(p1!=NULL || p2!=NULL){
            tmp = carry+(p1!=NULL ? p1->val : 0) + (p2!=NULL ? p2->val : 0);
            ListNode *node = (ListNode*)malloc(sizeof(ListNode));
            if(tmp>=10){
                node->val = tmp%10;
                carry = 1;
            }
            else{
                node->val = tmp;
                carry = 0;
            }
            p->next = node;
            p = p->next;
            p1 = (p1!=NULL ? p1->next : NULL); 
            p2 = (p2!=NULL ? p2->next : NULL);
        }
        if(1==carry){
            ListNode *node = (ListNode*)malloc(sizeof(ListNode));
			node->val = carry;
            p->next = node;
            p = p->next;
        }
		p = head.next;
		while(p!=NULL){
			cout << p->val << endl;
			p = p->next;
		}
        return head.next;
    }
};

int main(int argc, char *argv[]){
	ListNode *head1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
	head1->next = NULL;
	head2->next = NULL;
	ListNode *node1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *node2 = (ListNode*)malloc(sizeof(ListNode));
	node1->val = 9;
	node2->val = 6;
	head1->next = node1;
	head2->next = node2;
	node1->next = NULL;
	node2->next = NULL;
	ListNode *node3 = (ListNode*)malloc(sizeof(ListNode));
	node3->val = 9;
	node3->next = NULL;
	node2->next = node3;
	Solution sol;
	sol.addTwoNumbers(head1->next,head2->next);		
	return 0;
}	
