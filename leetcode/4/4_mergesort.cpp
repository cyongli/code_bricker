
/*链表排序的mergesort版本*/

#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	//链表归并排序
	if(head == NULL || head->next == NULL)return head;
	else
	    {
		//快慢指针找到中间节点
		ListNode *fast = head,*slow = head;
		while(fast->next != NULL && fast->next->next != NULL)
		    {
			fast = fast->next->next;
			slow = slow->next;
		    }
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		fast = sortList(head);//前半段排序
		slow = sortList(slow);//后半段排序
		return merge(fast,slow);
	    }

    }
    // merge two sorted list to one
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
	if(head1 == NULL)return head2;
	if(head2 == NULL)return head1;
	ListNode *res , *p ;
	if(head1->val < head2->val)
	    {res = head1; head1 = head1->next;}
	else{res = head2; head2 = head2->next;}
	p = res;

	while(head1 != NULL && head2 != NULL)
	    {
		if(head1->val < head2->val)
		    {
			p->next = head1;
			head1 = head1->next;
		    }
		else
		    {
			p->next = head2;
			head2 = head2->next;
		    }
		p = p->next;
	    }
	if(head1 != NULL)p->next = head1;
	else if(head2 != NULL)p->next = head2;
	return res;
    }
};

int main(int argc,char* argv[]){
    //srand(time(NULL));
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    FILE* fi = fopen(argv[2],"r");
    fscanf(fi,"%d\n",&(head->val));
    //head->val = rand() % (stoi(argv[2]));
    for(int i=0;i<stoi(argv[1])-1;i++){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//node->val = rand() % (stoi(argv[2]));
	fscanf(fi,"%d\n",&(node->val));
	node->next = head->next;
	head->next = node;
    }
    fclose(fi);
    ListNode* p = head;
    // while(p!=NULL){
    // 	cout << p->val << endl;
    // 	p=p->next;
    // }
    // cout << "after sort" << endl;

    clock_t start = clock();
    Solution sol;
    p = sol.sortList(head);
    clock_t end = clock();
    cout << (end-start)/CLOCKS_PER_SEC << endl;
    //p = head;
    // while(p != NULL){
    // 	cout << p->val << endl;
    // 	p=p->next;
    // }
    return 0;
}
