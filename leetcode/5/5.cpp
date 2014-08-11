#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
} ListNode;

class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
	ListNode* res = head->next;
	while(res != NULL){
	    return 
    }
};

int main(int argc, char*argv){
    File fi = fopen(argv[1],"r");
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    for(int i=0;i<stoi(argv[1]);i++){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	fscanf(fi,"%d\n",&(node->val));
	node->next = head->next;
	head->next = node;
    }
    fclose(fi);

    Solution sol;
    sol.insertionSortList(head);
    return 0;
}
