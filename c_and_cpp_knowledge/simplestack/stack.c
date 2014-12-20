#include<stdio.h>
#include "qsort.c"

#define PUSH(elem) ((*top)=elem,++top)
#define POP(elem) (--top,elem=(*top))
#define STACK_NOT_EMPTY (stack<top)

int main(int argc,char*argv[]){
  int stack_size = atoi(argv[1]);
  int stack[stack_size];
  int* top = stack;
  int i=0,elem=0;
  for(i=0;i<stack_size;i++){
    scanf("%d",&elem);
    PUSH(elem);
  }
  while(STACK_NOT_EMPTY){
    POP(elem);
    printf("%d\n",elem);
  }
}
