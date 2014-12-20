#include<iostream>
using namespace std;

typedef struct RandomListNode{
	int label;
	RandomListNode *next, *random;
}RandomListNode;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(head==NULL) return NULL;
    	RandomListNode *copyHead;
		RandomListNode *curr = head;
		RandomListNode *next = NULL;
		while(curr != NULL){
			RandomListNode *copy = (RandomListNode*)malloc(sizeof(RandomListNode));
			copy->label = curr->label;
			copy->next = curr->next;
			copy->random = curr->random;
			next = curr->next;
			curr->next = copy;
			curr = next;
		}
		curr = head;
		while(curr!=NULL){
		    if(curr->random!=NULL){
			    curr->next->random = curr->random->next;
		    }
			curr = curr->next->next;
		}	
		curr = head;
		copyHead = head->next;
	    next = NULL;
		while(curr->next!=NULL){
		    next = curr->next;
			curr->next = curr->next->next;
			curr=next;
		}
		return copyHead;
		
    }
};

int main(int argc, char* argv[]){

	return 0;
}
