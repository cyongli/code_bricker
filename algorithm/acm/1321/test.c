#include<stdio.h>

int main(){
  int n,k,i,j;
  char chess[8];
  char test[8][8];
  while(scanf("%d %d",&n,&k)!=EOF){
    if(n==-1 && k==-1) break;
    for(i=0;i<n;i++){
      scanf("%s",chess);
      for(j=0;j<n;j++){
	if(chess[j]=='.')
	  test[i][j]='A';
        else if(chess[j]=='#')
	  test[i][j]='a';
	else test[i][j]='X';    
      }
      test[i][n]='\0';
      printf("%s\n",chess);
    }
    for(i=0;i<n;i++)
      printf("%s\n",test[i]);
  }
  return 0;
}    
