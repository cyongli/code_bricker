/*题目大意:删除链表中倒数第n个元素
 * 三个指针,front,post,curr();
 * front先前进n步,然后post,front同时前进，直到front->next==NULL;
 * 然后curr=post->next;
 * 再者post->next = curr->next;
 * 不直接用post->next=front的原因是如果n==1,front既是要删除的元素
 * 同时加入头指针使得删除链表第一个元素时更好操作
 */


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = (ListNode*)malloc(sizeof(ListNode));
        first->next = head;
        ListNode *front = first;
        ListNode *post = first;
        ListNode *curr;
        for(int i=0;i<n;i++){
            front = front->next;
        }
        while(front->next != NULL){
            front = front->next;
            post = post->next;
        }
        curr = post->next;
        post->next = curr->next;
        delete curr;
        return first->next;
    }
};
