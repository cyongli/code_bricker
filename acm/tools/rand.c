#include<stdio.h>
#include<time.h>
//#include<stdlib.h>

int main(){
  srand((int)time(NULL));
  int a =1000+rand()%3000;
  printf("%d\n",a);
}
