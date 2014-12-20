
/*
  问题描述:4*4的方格中放了16颗棋子，棋子或白或黑。现在给出他们的初始状态，每次你可以翻转一个棋子，
           但是规定必须把它周围四个方向的棋子同时翻转(可能有3,4,5个棋子一起翻转的情况)。
           问：是否能够翻转到全黑或者全白的状态，如果能，需要几步完成？

  解题思路：看到棋子是2种状态，就想到了位运算，而棋盘只有16路，正好用一个int变量存储这16个状态。
            把初始状态看成一个节点，每次选取16个棋子中的一个进行翻转得到的新的状态为下一个节点，由此BFS即可找到结果。
           

*/

 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 4
#define MAX_STATE 65536

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

int convert(char c){
  return (c=='w')?0:1;
}

int flipPiece(int state_id,int pos){
  state_id ^= (1<<pos);
  if(pos >= 4)
    state_id ^= (1<<(pos-4));
  if(pos+4<SIZE*SIZE)
    state_id ^= (1<<(pos+4));
  if(pos%4!=0)
    state_id ^= (1<<(pos-1));
  if(pos%4!=3)
    state_id ^= (1<<(pos+1));
  return state_id;
}

int main(){

  int i,j,current_state_id=0;
  int state[MAX_STATE];
  init();
  memset(state,-1,sizeof(state));

  char flip[SIZE][SIZE];
  char color[SIZE];
  for(i=0;i<SIZE;i++){
    scanf("%s",color);
    for(j=0;j<SIZE;j++)
      flip[i][j]=color[j];
  }
  for(i=0;i<SIZE;i++)
    for(j=0;j<SIZE;j++)
      current_state_id += convert(flip[i][j])<<(i*4+j);
 
  if(current_state_id == 0 || current_state_id == 65535){
    printf("0\n");
    return 0;
  }
  state[current_state_id]=0;
  enqueue(current_state_id);
  int next_state_id;

  while(empty() != 0){
    current_state_id = dequeue();
    for(i=0;i<SIZE*SIZE;i++){
      next_state_id=flipPiece(current_state_id,i);
      if(next_state_id==0 || next_state_id==65535){
	printf("%d\n",state[current_state_id]+1);
	return 0;
      }
      if(state[next_state_id] == -1){
	state[next_state_id]=state[current_state_id]+1;
	enqueue(next_state_id);
      }
    }
  }
  printf("Impossible\n");
  return 0;
} 
