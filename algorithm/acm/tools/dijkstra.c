#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"linkedlist.h"

const int INF = INT_MAX;

typedef struct{
  int data;//顶点号
  int weight;//边的权重
  struct list_node list;
}node;

int extract_min(int*distance,int*visited,int n){
  int i,pos,min;
  for(i=1;visited[i]==1;i++);
  pos = i;min=distance[i];  
  for(i=pos+1;i<=n;i++)
    if(visited[i]==0 && distance[i]<min)
      { min = distance[i];pos=i;}
  return pos;
}


void dijkstra(struct list_node*graph,int n){
  int i,j,num=n;
  int* distance = (int*)malloc(sizeof(int)*(n+1));
  int* visited = (int*)malloc(sizeof(int)*(n+1)); 
  int* prev = (int*)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++){
    visited[i]=0;
    distance[i]=INF;
  }
  distance[1]=0;
  visited[1]=1;
  prev[1]=1;
  num = n-2;
  struct list_node*pos;
  list_for_each(pos,&graph[1]){
    node*tmp = list_entry(pos,node,list);
    distance[tmp->data] = tmp->weight;
    prev[tmp->data]=1;
  }
  while(num--!=0){
    int u = extract_min(distance,visited,n);
    visited[u]=1;
    list_for_each(pos,&graph[u]){
      node*tmp=list_entry(pos,node,list);
      if(visited[tmp->data]==0 && distance[tmp->data]>distance[u]+tmp->weight)
      {
  	distance[tmp->data]=distance[u]+tmp->weight;
  	prev[tmp->data]=u;
      }
    }
  }
  for(i=1;i<=n;i++)
    printf("%d:%d,%d  ",i,distance[i],prev[i]);
  printf("\n");
  
}

int createGraph(struct list_node*graph,int n,int e){
  int i,j;
  for(i=1;i<=n;i++)
    INIT_LIST_HEAD(&graph[i]);
  printf("input the pair of nodes:\n");
  for(i=1;i<=e;i++){
    node*tmp = (node*)malloc(sizeof(node));
    scanf("%d,%d,%d",&j,&tmp->data,&tmp->weight);
    list_add(&graph[j],&tmp->list);
  }
}


int main(){
  int i,j,n,e,*visited,*distance,*prev;
  printf("input the number of nodes and edges:");
  scanf("%d,%d",&n,&e);
  struct list_node*graph = (struct list_node*)malloc(sizeof(struct list_node)*(n+1)); 
  createGraph(graph,n,e);
  dijkstra(graph,n);
}
