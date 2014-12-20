/*
  题目大意:在一个图中信息从节点沿边传递，边的权重代表传播时间，问从哪个节点信息散播的最快以及散播时间
           可以这么假设，有A,B,C,D节点，
           信息从节点A开始传播，C最后收到信息，时间为n1
           信息从节点B开始传播，A最后收到信息，时间为n2
           以此类推，n3,n4找出其中的最小值
  解题思路:floyd-warshall找出从任一个节点出发信息到达其他节点的时间，选取每组中接收到信息的最后时间，
           在从其中找出最小值，即为结果
*/

#include<stdio.h>
#include<limits.h>

#define INF INT_MAX

int graph[101][101];
int dis[101][101];
int res[101];

void floyd_warshall(int n){
  int i,j,k;
  for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
	if(dis[i][k]!=INF && dis[k][j]!=INF && dis[i][k]+dis[k][j]<dis[i][j])
	  dis[i][j] = dis[i][k]+dis[k][j];
}

int main(){
  int n,cont,e,i,j;
  scanf("%d",&n);
  while(n!=0){
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
	graph[i][j]=INF;
      graph[i][i]=0;
    }
    for(i=1;i<=n;i++){
      scanf("%d",&cont);
      for(j=1;j<=cont;j++){
	scanf("%d",&e);
	if(e==0) break;
	scanf("%d",&graph[i][e]);
      }
    }
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
	dis[i][j]=graph[i][j];
    floyd_warshall(n);
    int max;
    for(i=1;i<=n;i++){
      max=dis[i][1];
      for(j=1;j<=n;j++){
	if(dis[i][j]!=max && dis[i][j]>max)
	  max=dis[i][j];
      }
      res[i]=max;
    }
    int min = INF,pos=1;
    for(i=1;i<=n;i++)
      if(res[i]<min)
	{min = res[i];pos = i;}
    if(min==INF)
      printf("disjoint\n");
    else
      printf("%d %d\n",pos,min);
    scanf("%d",&n);
  }
  /* for(i=1;i<=n;i++){ */
  /*   for(j=1;j<=n;j++){ */
  /*     if(graph[i][j]==INF) */
  /* 	printf("%5s","INF"); */
  /*     else */
  /* 	printf("%5d",graph[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /* } */
  /* printf("\n"); */
  /* for(i=1;i<=n;i++){ */
  /*   for(j=1;j<=n;j++){ */
  /*     if(dis[i][j]==INF) */
  /* 	printf("%5s","INF"); */
  /*     else */
  /* 	printf("%5d",dis[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /* } */
  return 0;
}
