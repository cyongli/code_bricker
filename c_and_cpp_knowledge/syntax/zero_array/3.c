#include<stdio.h>
#include<stdlib.h>

struct line{
  int length;
  char contents[];
};

int main(){
  struct line * thisline = (struct line*)malloc(sizeof(struct line));
  thisline->length = 12;
  printf("%p,%p\n",thisline,thisline->contents);
  for(int i=0;i<12;i++)
    thisline->contents[i]=i;
  /* for(int i=0;i<12;i++) */
  /*   printf("%d\n",thisline->contents[i]); */
  for(int i=0;i<12;i++)
    printf("%d ",thisline->contents[i]);
  if(thisline->contents)
    printf("%p\n",thisline->contents);
  return 0;
}
