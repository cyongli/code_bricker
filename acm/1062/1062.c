/*
  题目大意:探险家想娶酋长的女儿，需要拿10000金币或者其他物品代替。
           代替物品可以再找部落其他人或买或换得到，整个交易链条中人员等级之差必须
           保持在一定范围内，求最小的金币数。
  解题思路:实际上就是一个单源最短路径问题，关键在于对等级限制的处理，只需枚举即可。
           枚举[lev-M,lev]~[lev,lev+M]所有区间的情况，找出最优解即可。

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct list_node{
  struct list_node * next;
};

static inline void INIT_LIST_HEAD(struct list_node* head){
  head->next = NULL;
}

static inline void list_add(struct list_node*head,struct list_node* new){
  new->next = head->next;
  head->next = new;
}

#define offsetof(type,member) ((size_t)(&((type*)0)->member))

#define container_of(ptr,type,member)  (type*)((char*)ptr-offsetof(type,member))

#define list_entry(ptr,type,member)  container_of(ptr,type,member)

#define list_for_each(pos,head)	 for(pos=(head)->next;pos!=NULL;pos=pos->next)

const int INF=1e8;

typedef struct{
  int num;//顶点号
  int money;//金币数
  int weight;//权重
  int pri;//级别
  struct list_node list;
}node;

typedef struct{
  int money;//金币数
  int pri;//级别
  struct list_node head;
}point;

int extract_min(int*distance,int*visited,int n){
  int i,pos,min;
  for(i=1;visited[i]==1;i++);
  pos = i;min=distance[i];  
  for(i=pos+1;i<=n;i++)
    if(visited[i]==0 && distance[i]<min)
      { min = distance[i];pos=i;}
  return pos;
}

void dijkstra(point*graph,int n,int*distance,int*visited,int low,int high)
{
  int i,j,num=n;
  for(i=1;i<=n;i++){
    if(graph[i].pri>=low && graph[i].pri<=high)
      visited[i]=0;
    else visited[i] = 1;
    distance[i]=INF;
  }
  distance[1]=0;
  num = n-1;
  struct list_node*pos;
  while(num--!=0){
    int u = extract_min(distance,visited,n);
    if(u>n) break;
    visited[u]=1;
    list_for_each(pos,&(graph[u].head)){
      node*tmp=list_entry(pos,node,list);
      if(visited[tmp->num]==0 && distance[tmp->num]>distance[u]+tmp->weight)
  	distance[tmp->num]=distance[u]+tmp->weight;
    }
  }
}

void addEdge(point*graph,int i,int j,int weight){
  node*tmp=(node*)malloc(sizeof(node));
  tmp->num=j;
  tmp->weight=weight;
  list_add(&(graph[i].head),&tmp->list);
}

int main(){
  int m,n,x,t,v;
  int i,j;
  scanf("%d %d",&m,&n);
  point*graph = (point*)malloc(sizeof(point)*(n+1));
  for(i=1;i<=n;i++)
    INIT_LIST_HEAD(&(graph[i].head));
  for(i=1;i<=n;i++){
    scanf("%d %d %d",&(graph[i].money),&(graph[i].pri),&x);
    for(j=1;j<=x;j++){
      scanf("%d %d",&t,&v);
      addEdge(graph,i,t,v);
    }
  }
  struct list_node*pos;
  for(i=1;i<=n;i++){
    list_for_each(pos,&(graph[i].head)){
      node*tmp = list_entry(pos,node,list);
      tmp->pri=graph[tmp->num].pri;
      tmp->money=graph[tmp->num].money;
    }
  }
  int* distance = (int*)malloc(sizeof(int)*(n+1));
  int* visited = (int*)malloc(sizeof(int)*(n+1)); 
  int min = INF;
  for(i=0;i<=m;i++){
    dijkstra(graph,n,distance,visited,graph[1].pri-m+i,graph[1].pri+i);
    for(j=1;j<=n;j++)
      distance[j] += graph[j].money;
    for(j=1;j<=n;j++)
      if(distance[j]<min)
    	min = distance[j];
  }
  printf("%d\n",min);
  return 0;
}
