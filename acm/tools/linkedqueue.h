#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include<stdio.h>

struct node{
  int data;
  struct node*next;
}*rear,*front;

void init(){
  front = (struct node*)malloc(sizeof(struct node));
  front->data = 0;
  front->next = NULL;
  rear = front;
}

int empty(){
  return (rear == front)?0:1;
}

void enqueue(int data){
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data = data;
  rear->next = tmp;
  rear = tmp;
}

int dequeue(){
  struct node* tmp = front->next;
  front->next = tmp->next;
  int data = tmp->data;
  if(tmp == rear) rear = front;
  free(tmp);
  return data;
}

void display(){
  struct node*current = front->next;
  while(current!=NULL){
    printf("%d\n",current->data);
    current = current->next;
  }
}

#endif
