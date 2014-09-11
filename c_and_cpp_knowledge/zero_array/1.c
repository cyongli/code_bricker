#include<stdio.h>

struct str{
  int len;
  char s[0];
};

struct foo{
  struct str * a;
};

int main(int argc,char ** argv){
  struct foo f = {0};
  printf("%d\n",sizeof(f.a->s));
  if(f.a->s){
    printf("%p\n",f.a->s);
  }
  return 0;
}
