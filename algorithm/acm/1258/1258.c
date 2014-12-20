#include<stdio.h>
#include<string.h>
#include<limits.h>

#define N 110
#define INF INT_MAX
int graph[N][N];
int visited[N];
int pre[N];
int key[N];

int extract_min(int n){
  int i,min=INF,pos;
  for(i=1;i<=n;i++)
    if(visited[i]==0 && key[i]<min)
      {min=key[i];pos=i;}
  return pos;
}

int prim(int n){
  int i,num=0,u;
  memset(visited,0,sizeof(int)*N);
  memset(pre,0,sizeof(int)*N);
  for(i=2;i<=n;i++)
    key[i]=INF;
  key[1]=0;
  while((num++)<n){
    u = extract_min(n);
    visited[u]=1;
    for(i=1;i<=n;i++)
      if(visited[i]==0 && graph[u][i]<key[i])
	{key[i]=graph[u][i];pre[i]=u;}
  }
  int res=0;
  for(i=1;i<=n;i++)
    res += graph[i][pre[i]];
  return res;
}

int main(){
  int n,i,j;
  while(scanf("%d",&n)!=EOF && n){
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
	scanf("%d",&(graph[i][j]));
    printf("%d\n",prim(n));
  }
  return 0;
}
