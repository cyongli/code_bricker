/*
  题目大意:多个小立方体面面相连成为一个空间集合体，整个空间几何体可由一个大的长方体包括。
           与外面相连的小立方体方格是需要加防护膜的，给定一个长宽高为n,m,k的大长方体，以及小立方体
           在其中的位置，求需要加防护膜的面数。
  解题思路:在大长方体外围加上一层，有(0,0,0)开始，floofill计算有多少个面与外界相连。
  注意:不要用递归，会溢出。
 */

#include<stdio.h>
#include<string.h>

int grid[65][65][65];
int n,m,k,l;
int stepX[6] = {-1,0,0,1,0,0};
int stepY[6] = {0,-1,0,0,1,0};
int stepZ[6] = {0,0,-1,0,0,1};

void mark(int x,int y,int z){
  if(x>=0&&x<=n&&grid[x+1][y][z]==0)
    {grid[x+1][y][z]=2;mark(x+1,y,z);}
  if(x>=1&&x<=n+1&&grid[x-1][y][z]==0)
    {grid[x-1][y][z]=2,mark(x-1,y,z);}
  if(y>=0&&y<=m&&grid[x][y+1][z]==0)
    {grid[x][y+1][z]=2;mark(x,y+1,z);}
  if(y>=1&&y<=m+1&&grid[x][y-1][z]==0)
    {grid[x][y-1][z]=2;mark(x,y-1,z);}
  if(z>=0&&z<=k&&grid[x][y][z+1]==0)
    {grid[x][y][z+1]=2;mark(x,y,z+1);}
  if(z>=1&&z<=k+1&&grid[x][y][z-1]==0)
    {grid[x][y][z-1]=2;mark(x,y,z-1);}
}

int shielding(int n,int m,int k){
  int x,y,z,l,result=0;
  grid[0][0][0]=2;
  mark(0,0,0);
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
  while(n!=0 && m!=0 && k!=0 && l!=0){
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
