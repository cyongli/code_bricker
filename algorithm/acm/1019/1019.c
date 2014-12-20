/*
  题目描述：数字系列s1s2s3...sk。前80个序列如下:
            11212312341234512345612345671234567812345678912345678910123456789101112345678910
            判断第n个字符为什么
  解题思路：1.用数组a记录每组数据的个数，用数组start记录每组数据的第一个数据在序列中的起始位置
              a[i]=a[i-1]+2*m1-m2,其中m1,m2分别为i,i-1的十进制位数
              start[1]=1,start[i] = start[i-1]+a[i-1];
              然后根据pos的大小判断位数会由哪个数产生，然后再次判断具体的数字
            2.可以换一种划分方式
              1 12 123 1234 12345 123456 1234567 12345678 123456789 12345678910 1234567891011 123456789101112
              如此在进行计算可以更加简单
*/

#include<stdio.h>
#include<string.h>
#include<stddef.h>

#define NUM 50000

int judge(int x) //判断数的位数  
{  
  int count = 1;
  while(x / 10)  	
    {  
      count++;  
      x /= 10;  
    }  
  return count;  
}  

int power(int length){
  int i=0,result=1;
  for(i=0;i<length;i++)
    result *= 10;
  return result;
}

int digit(int num,int pos){
  int i=0,m=1,length=0;
  m=judge(num);
  if(pos<=m){
    for(i=0;i<m-pos;i++)
      num /= 10;
    return num%10;
  }
  pos = pos-m;
  for(i=1;length<pos;i++)
    length += judge(i);
  return ((i-1)/power(length-pos))%10;
}

int main(){
  int i,j,codelength=1,base=10,testcase,pos;
  int a[NUM];
  size_t start[NUM];
  memset(a,0,sizeof(a));
  a[1]=2;start[1]=1;
  for(i=1;i<NUM-1;i++){
    a[i+1]=a[i]+codelength;
    if((i+1)%base == 0){
      codelength++;
      a[i+1] += 2;
      base *= 10;
    }
    start[i+1]=a[i]+start[i];
  }
  i=j=0;
  scanf("%d",&testcase);
  while((j++)<testcase){
    scanf("%d",&pos);
    for(i=1;start[i]<=pos;i++);
    printf("%d\n",digit(i-1,pos+1-start[i-1]));
  }
  return 0;
}
