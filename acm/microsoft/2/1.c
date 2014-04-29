#include<stdio.h>

typedef unsigned long long int uint64_t;
int tstNum;
uint64_t num;
uint64_t result[100];

int get_result(uint64_t result [],uint64_t num,int* len){
  if(num == 0){
    if((*len)>=3 && (*len)<=100)
      return 1;
    else return 0;
  }
  uint64_t round = num;
  uint64_t limit = 2*num;
  while(round <= limit){
    if((*len)>=1 && result[(*len)-1] <= round){
      return 0;
    }
    if((*len) >= 1 && result[(*len)-1]%round != 0){
      round++;
      continue;
    }
    result[(*len)++] = round;
    if(get_result(result,round-num,len)==1)
      return 1;
    (*len)--;
    round++;
  }
  return 0;
}

int main(){
  scanf("%d",&tstNum);
  int i=0,j=0;
  int len=0;
  for(i=0;i<tstNum;i++){
    scanf("%lld",&num);
    if(get_result(result,num,&len)==0)
      printf("case %d: no solution\n",i+1);
    else {
      printf("Case %d: ",i+1);
      for(j=0;j<len;j++)
	printf("%llu ",result[j]);
      printf("\n");
    }
  }
  return 0;
}
