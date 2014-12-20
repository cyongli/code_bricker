#include<iostream>
#include<fstream>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode *next;
}ListNode;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(k==0 || head==NULL) return head;
        ListNode *fast = head;
        ListNode *slow = head;
		int i = 0;
		for(i=0;fast!=NULL;fast=fast->next,++i);
		k = k%i;
		fast = head;
		//cout << k << endl;
        for(i=0;i<k && fast!=NULL;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            return head;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};

int main(int argc, char* argv[]){
	ifstream fi(argv[1],ios::in);
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	int val=0;
	for(int i=0;i<stoi(argv[2]);i++){
		ListNode *node = (ListNode*)malloc(sizeof(ListNode));
		fi >> (node->val);
		node->next = head->next;
		head->next = node;
	}
	Solution sol;
	ListNode *p = sol.rotateRight(head->next,stoi(argv[3]));
	while(p!=NULL){
		cout << p->val << endl;
		p = p->next;
	}

}
