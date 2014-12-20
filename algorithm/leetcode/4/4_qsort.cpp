
/*链表排序的qsort版本，用的实现方法时算法导论的方法，
  理论上应该时O(nlgn)的，但是可能由于partition选取
  的不对，结果不对。
*/

#include<iostream>
#include<ctime>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

class Solution {	
private:
    ListNode* tmp;
public:
    Solution(){
	tmp = (ListNode*)malloc(sizeof(ListNode));
    }

    void swap(ListNode* left, ListNode* right){
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
    
    ListNode* partition(ListNode* head, ListNode* tail){
	ListNode* key = tail;
        tmp->next = head;
        ListNode* left = tmp;
        ListNode* right = head;
        while(right != tail){
	    if(right->val <= key->val){
		left = left->next;
		swap(left,right);
	    }
	    right = right->next;
        }
        swap(left->next,tail);
        return left;
    }
    
    void qsort(ListNode* head,ListNode* tail){
        if(head == tail)
	    return;
        else if(tail->next == head)
	    return;
        else
	 {
	     ListNode* q = partition(head,tail);
	     qsort(head,q);
	     qsort(q->next->next,tail);
	 }
    }
    
    ListNode* sortList(ListNode* head){
        if(head == NULL)
	    return head;
        ListNode* tail;
        for(tail=head; tail->next != NULL; tail = tail->next);
        qsort(head,tail);
        return head;
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
    sol.sortList(head);
    clock_t end = clock();
    cout << (end-start)/CLOCKS_PER_SEC << endl;
    p = head;
    // while(p!=NULL){
    // 	cout << p->val << endl;
    // 	p=p->next;
    // }
    return 0;
}
