#include<stdio.h>

typedef struct {
  int father;
  int weight;
  int height;
} node;

int tstNum=0;
node tree[100000];
#define MOD 1000000007
#define MAGIC 12347
typedef long long int int64_t;

int get_father(int node,int u){
  if(node == u) return 0;
  int father = tree[node-1].father;
  while(father >= u){
    if(father == u) return 0;
    father = tree[father-1].father;
  }
  return 1;
}

int main(){
  scanf("%d",&tstNum);
  int i=0,j=0,k=0;
  int nodeNum;
  int father;
  int operNum;
  int u,l,r,delta;
  for(i=1;i<=tstNum;i++){
    scanf("%d",&nodeNum);
    tree[0].height=1;
    tree[0].weight=0;
    tree[0].father=0;
    for(j=2;j<=nodeNum;j++){
      scanf("%d",&father);
      tree[j-1].father=father;
      tree[j-1].weight=0;
      tree[j-1].height=tree[father-1].height+1;
    }
    scanf("%d",&operNum);
    for(j=1;j<=operNum;j++){
      scanf("%d %d %d %d",&u,&l,&r,&delta);
      for(k=u;k<=nodeNum;k++)
	if(get_father(k,u)==0 && tree[k-1].height>=l 
           && tree[k-1].height<=r)
	  tree[k-1].weight += delta;
    }
    int64_t hash=0;
    /* printf("\n"); */
    /* for(j=1;j<=nodeNum;j++) */
    /*   printf("%d ",tree[j-1].weight); */
    for(j=1;j<=nodeNum;j++){
      hash = (hash*MAGIC+tree[j-1].weight) % MOD;
    }
    printf("Case %d: %lld\n",i,hash);  
  }
  return 0;
}
