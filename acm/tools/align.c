#include<stdio.h>

#pragma pack(1)

struct test{
  int a:3;
  int b:5;
};//__attribute__((aligned(2)));

int main(){
  printf("%d\n",sizeof(struct test));
}
