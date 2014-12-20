#include<stdio.h>
#include<time.h>

int main(){
  time_t biggest = 0x7FFFFFFF;
  printf("%ld\n",sizeof('A'));
  printf("biggest=%s\n", ctime(&biggest));
  //printf("%s\n",typeof(biggest));
  return 0;
}
