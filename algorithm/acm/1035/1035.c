
/*
  题目描述：这题是字符处理的一个典型题目,主要是在给出的词典中查找指定的单词，如果找到，就输出正确的，如果找不到完全一样的,就：
            1.一个字母不同的
            2.多一个字符的
            3.少一个字符的
  解题思路：
            判断两个字符串长度之差的是否为1
            判断两个字符串中不等的字符个数是否为1或是否相等
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

static inline int MIN(int x,int y,int z){
  return (x<y)?(x<z?x:z):(y<z?y:z);
}

int lev[16][16];

int editDistance(char* s1,char* s2){
  /*编辑距离算法，可以求出两个字符串的编辑距离，此题中不需要用到如此复杂的算法*/
  int i,j,len1=strlen(s1),len2=strlen(s2);
  lev[0][0]=0;
  /*赋值语句的返回结果是lev[i][0],此处可以这么用，其他地方要注意*/
  for(i=1;i<=len1 && (lev[i][0]=i);i++);
  for(j=1;j<=len2 && (lev[0][j]=j);j++);
  for(i=0;i<len1;i++){
    for(j=0;j<len2;j++){
      int a=0;
      if(s1[i]==s2[j]) a=0;
      else a=1;
      lev[i+1][j+1]=MIN(lev[i][j+1]+1,lev[i+1][j]+1,lev[i][j]+a);
    }
  }
  return lev[len1][len2];
}

int editDis(char*s1,char*s2){
  int i,j,edit=0,len1=strlen(s1),len2=strlen(s2);
  for(i=0,j=0;(len1<len2)?(j<len2):(i<len1);i++,j++){
    if(s1[i]!=s2[j]){
      edit++;
      if(len1==len2) continue;
      (len1<len2)?(i--):(j--);
    }
  }
  return edit;
}

int main(){
  char check[51][16],dic[10001][16],*result;
  result = (char*)malloc(15);
  int i=0,j=0,dicNumber=0,checkNumber=0;
  scanf("%s",dic[i]);
  while(strcmp(dic[i],"#")!=0){
    i += 1;
  scanf("%s",dic[i]);
  }
  dicNumber = i;
  scanf("%s",check[j]);
  while(strcmp(check[j],"#")!=0){
    j += 1;
    scanf("%s",check[j]);
  }
  checkNumber = j;
  int isCorrect = 0;
  for(j=0;j<checkNumber;j++){
    strcpy(result,check[j]);
    strcat(result,": ");
    for(i=0;i<dicNumber;i++){
      if(abs(strlen(check[j])-strlen(dic[i]))>1)
	continue;
      if(strcmp(check[j],dic[i])==0){
	isCorrect = 1;
	printf("%s is correct\n",check[j]);
	break;
      }
      if(editDis(check[j],dic[i])==1){
	strcat(strcat(result,dic[i])," ");
      }
      isCorrect = 0;
    }
    if(isCorrect == 0){
      result[strlen(result)-1]='\0';
      printf("%s\n",result);
    }
  }
  return 0;
}
