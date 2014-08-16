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
    ListNode *reverse(ListNode *head, ListNode *tail){
        ListNode *p = head->next;
        head->next = tail->next;
        ListNode *next;
        ListNode *pre = p;
        while(p!=(tail->next)){
            next = p->next;
            p->next = head->next;
            head->next = p;
            p = next;
        }
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || k==1) return head;
        ListNode first(0);
        first.next = head;
        ListNode *pre = &first;
        ListNode *cur = head;
        while(true){
            int i;
            for(i=1;cur!=NULL && i<k;++i) cur=cur->next;
            if(cur==NULL) break;
            pre = reverse(pre,cur);
            cur = pre->next;
        }
        return first.next;
    }
};

int main(int argc, char *argv[]){
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	ListNode *node1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *node2 = (ListNode*)malloc(sizeof(ListNode));
	node1->val = 1;
	node2->val = 2;
	head->next = node1;
	node1->next = node2;
	node2->next = NULL;
	Solution sol;
	sol.reverseKGroup(head->next,2);		
	return 0;
}	
