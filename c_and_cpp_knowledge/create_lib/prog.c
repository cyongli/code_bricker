#include<stdio.h>

int main(){
  int x;
  ctest1(&x);
  printf("ctest1 Valx=%d\n",x);
  ctest2(&x);
  printf("ctest2 Valx=%d\n",x);
  return 0;
}
