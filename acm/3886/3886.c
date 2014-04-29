/*
  问题描述：给定一个由任意字母构成的带重全排列中，求某一序列所处的位置
  运算过程：从高位往低位算，每位所确定的序列位置为后面比当前位小的个数n乘以后面的位数m的阶乘，除以当前位到末尾的各组重复字母
            的重复个数的阶乘之积
            BANANA为(3*5!)/(2!*3!)+(2*3!)/(2!*2!)+1=34
            OMGWFTBBQ为(5*8!)/2!+(4*7!)/2!+(3*6!)/2!+(5*5!)/2!+(2*4!)/2!+(3*3!)/2!=112293 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64_t;

int64_t fact(int n){
  if(n==0 || n==1)
    return 1;
  else return n*fact(n-1);
}

int main(){
  int i=0,j=0,k=0,testcase,length;
  long long temp;
  int isExist[26],number[26],small[20];
  scanf("%d",&testcase);
  int64_t*result = (int64_t*)malloc(sizeof(int64_t)*testcase);
  char**input = (char**)malloc(sizeof(char*)*testcase);
  for(i=0;i<testcase;i++)
    input[i]=(char*)malloc(sizeof(char)*20);
  for(i=0;i<testcase;i++)
    scanf("%s",input[i]);
  while(j<testcase){
    result[j]=0;
    length = strlen(input[j]);
    for(k=0;k<length;k++)
      small[k]=0;
    for(i=0;i<length;i++){
      for(k=0;k<26;k++){
	number[k]=0;
      }
      for(k=i;k<length;k++){
	number[(int)input[j][k]-65]++;
      }
      for(k=i+1;k<length;k++){
	if((int)input[j][i]>(int)input[j][k]){
	  small[i]++;
	}
      }
      temp = small[i]*fact(length-i-1);
      if(small[i]>0){
	for(k=0;k<26;k++){
	  temp /= fact(number[k]);
	}
      }
      result[j] += temp;
    }
    j += 1;
  }
  for(i=0;i<testcase;i++)
    printf("%lld\n",result[i]);
   return 0;
}
