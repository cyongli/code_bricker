/*
  题目大意:现有n*n棋盘，棋盘上标'#'的位置可以放置棋子，标'.'的地方不能放棋子，且所有棋子在不同行不同列
           假设现在有k个棋子(k<=n)，问有多少种放法?
  解题思路:1.把标'#'的格子看成树的节点，假想依据棋盘建立一棵树，然后进行深度遍历
             dfs递归遍历的过程: 
              遍历过程中如何遍历到了k个满足条件的节点，就把结果加上1,返回上一级;
              如果剩下的棋盘行数小于还需要放置的棋子数，直接进行剪枝；
              对当前行的标'#'节点进行深度遍历;
              由于k可能小于n，所以直接越过当前行进行遍历
           2.参考组合数学中的棋盘多项式(rook polynomial)

*/

#include<stdio.h>
#include<string.h>

int rook[8][8];
int n,k;
int ans;
int visited[8];

void dfs(int pos,int num){
  if(num==k)
    {ans++;return;}
  if(n-pos<k-num)
    return;
  int i;
  for(i=0;i<n;i++){
    if(rook[pos][i] && visited[i]==0){
      visited[i]=1;
      dfs(pos+1,num+1);
      visited[i]=0;
    }
  }
  dfs(pos+1,num);//此处是因为k<n可能出现
}

int main(){
  int i,j;
  char chess[9];
  while(scanf("%d %d",&n,&k)!=EOF){
    if(n==-1 && k==-1) break;
    memset(rook,0,sizeof(rook));
    memset(visited,0,sizeof(visited));
    for(i=0;i<n;i++){
      scanf("%s",chess);
      for(j=0;j<n;j++){
	if(chess[j]=='.')
	  rook[i][j]=0;
	else rook[i][j]=1;
      }
    }
    ans=0;
    dfs(0,0);
    printf("%d\n",ans);
  }
  return 0;
}
