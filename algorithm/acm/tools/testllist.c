#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

typedef struct node{
  int data;
  struct list_node list;
}mylist;

int main(){
  mylist*head = (mylist*)malloc(sizeof(mylist));
  INIT_LIST_HEAD(&head->list);
  int i=5;
  while(i-->0){
    mylist*tmp = (mylist*)malloc(sizeof(mylist));
    scanf("%d",&(tmp->data));
    list_add(&head->list,&tmp->list);
  }
  struct list_node * pos;
  list_for_each(pos,&head->list){
    mylist* tmp = list_entry(pos,mylist,list);
    printf("%d\n",tmp->data);
  }
  return 0;
}
