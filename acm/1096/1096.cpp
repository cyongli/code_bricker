#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

int grid[65][65][65];
int n,m,k,l;
int stepX[6] = {-1,0,0,1,0,0};
int stepY[6] = {0,-1,0,0,1,0};
int stepZ[6] = {0,0,-1,0,0,1};

typedef struct{
  int x;
  int y;
  int z;
}node;

void enpush(int x,int y,int z,stack<node>&mystack){
  if(x>=0&&x<=n&&grid[x+1][y][z]==0){
    node tmp = {x+1,y,z};
    mystack.push(tmp);
  }
  if(x>=1&&x<=n+1&&grid[x-1][y][z]==0){
    node tmp = {x-1,y,z};
    mystack.push(tmp);
  }
  if(y>=0&&y<=m&&grid[x][y+1][z]==0){
    node tmp = {x,y+1,z};
    mystack.push(tmp);
  }
  if(y>=1&&y<=m+1&&grid[x][y-1][z]==0){
    node tmp = {x,y-1,z};
    mystack.push(tmp);
  }
  if(z>=0&&z<=k&&grid[x][y][z+1]==0){
    node tmp = {x,y,z+1};
    mystack.push(tmp);
  }
  if(z>=1&&z<=k+1&&grid[x][y][z-1]==0){
    node tmp = {x,y,z-1};
    mystack.push(tmp);
  }
}

void mark(stack<node>&mystack){
  int x,y,z;
  while(mystack.empty()==false){
    node tmp = mystack.top();
    mystack.pop();
    x = tmp.x;y = tmp.y;z = tmp.z;
    grid[x][y][z]=2;
    enpush(x,y,z,mystack);
  }
}

int shielding(int n,int m,int k){
  int x,y,z,l,result=0;
  grid[0][0][0]=2;
  stack<node> mystack;
  enpush(0,0,0,mystack);
  mark(mystack);
  for(x=1;x<=n;x++)
    for(y=1;y<=m;y++)
      for(z=1;z<=k;z++)
	if(grid[x][y][z]==1){
	  for(l=0;l<6;l++)
	    if(grid[x+stepX[l]][y+stepY[l]][z+stepZ[l]]==2)
	      result++;
	}
  return result;
}

int main(){
  int i,pos,cord,x,y,z;
  scanf("%d %d %d %d",&n,&m,&k,&l);
  while(n!=0 || m!=0 || k!=0 || l!=0){
    memset(grid,0,sizeof(grid));
    cord = n*m;
    for(i=0;i<l;i++){
      scanf("%d",&pos);
      z = 1+pos/cord;
      y = 1+(pos%cord)/n;
      x = 1+pos%n;
      grid[x][y][z]=1;
    }
    printf("The number of faces needing shielding is %d.\n",shielding(n,m,k));
    scanf("%d %d %d %d",&n,&m,&k,&l);
  }
  return 0;
}
