/*
 *链表的插入排序算法
 *从头至尾遍历链表，找到第n个元素的合适插入位置，交换指针，插入数据
 * */

#include<iostream>
#include<string>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode* next;
}ListNode;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		if(head == NULL){
			return head;
		}
		ListNode* first = (ListNode*)malloc(sizeof(ListNode));
		first->next = head;
		ListNode* pos = first->next->next;
		ListNode* out,*in,*pri;
		while((out=pos) !=NULL){
			pos = pos->next;//out的位置会变化，pos=out的情况下，pos的位置实际也变了
			/*找到第n个元素的合适插入位置*/
			for(in=first; in->next->val <= out->val && in->next != out; in=in->next);
			for(pri=in; pri->next!=out; pri=pri->next);/*找到out的前驱指针，交换时用到*/
			pri->next = out->next;
			out->next = in->next;
			in->next = out;
			
			/*此方法实现时将第n个元素与前面的元素一个一个进行交换，不可取*/
			//for(in=first->next,pri=first; in->next!=out && first->next != out; pri=in,in=in->next);
			//while(first->next != out && out->val < in->val){
			//	pri->next = out;
			//	in->next = out->next;
			//	out->next = in;
			//	for(in=first->next,pri=first; in->next!=out && first->next != out; pri=in,in=in->next);
			//}
		}
		return first->next;
    }
};

int main(int argc, char* argv[]){
	FILE* fi = fopen(argv[1],"r");
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	for(int i=0;i<stoi(argv[2]);i++){
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		fscanf(fi,"%d\n",&(node->val));
		node->next = head->next;
		head->next = node;
	}
	Solution sol;
	ListNode* p = head->next;
	//while(p!=NULL){
	//	cout << p->val << endl;
	//	p = p->next;
	//}
	//cout << "after sort" << endl;
	p = sol.insertionSortList(head->next);
	while(p!=NULL){
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
