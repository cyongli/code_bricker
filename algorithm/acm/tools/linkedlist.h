
/*singly linked list*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct list_node{
  struct list_node * next;
};

static inline void INIT_LIST_HEAD(struct list_node* head){
  head->next = NULL;
}

static inline void list_add(struct list_node*head,struct list_node* new){
  new->next = head->next;
  head->next = new;
}

#define offsetof(type,member) ((size_t)(&((type*)0)->member))

#define container_of(ptr,type,member)({\
  const typeof(((type*)0)->member)* __mptr = ptr;\
  (type*)((char*)__mptr-offsetof(type,member));})

#define list_entry(ptr,type,member)\
  container_of(ptr,type,member)

#define list_for_each(pos,head)	\
    for(pos=(head)->next;pos!=NULL;pos=pos->next)

#endif
