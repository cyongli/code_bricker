#include<stdio.h>
#include<time.h>

typedef long long int int64_t;

int main(int argc,char*argv[]){
  int64_t i=0;
  int64_t a=0;
  clock_t start,end;
  start = clock();
  for(i=0;i<1e10;i++)
    a++;
  end = clock();
  printf("%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
  printf("%lld\n",a);
  return 0;
}
