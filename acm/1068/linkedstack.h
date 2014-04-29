
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include<stdlib.h>

struct node{
  int data;  
  struct node* next;
};

void init(struct node**head)
{
  *head = (struct node*)malloc(sizeof(struct node));
  (*head)->data = 0;
  (*head)->next = NULL;
}

int empty(struct node*head){
  return (head->next==NULL)?0:1;
}

void push(struct node* head,int data)
{
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->next = head->next;
  head->next = tmp;
}

void set(struct node*head,int data){
  head->next->data = data;
}

int pop(struct node*head){
  struct node* tmp = head->next;
  int data = tmp->data;
  head->next = tmp->next;
  free(tmp);
  return data;
}

void display(struct node* head){
  struct node* current = head->next;
  while(current != NULL){
    printf("%d\n",current->data);
    current = current->next;
  }
}

#endif
