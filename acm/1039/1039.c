/*
  题目大意：见算法黑书第372页,具体实现时做了一些改动,具体可以见代码
            
 */


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const double precision=1e-3;
const double inf=99999.0;

typedef struct node{
  double x;
  double y;
}point;

static inline max(int a,int b){
  return (a>b)?a:b;
}

int dblcmp(double p){
  if(fabs(p)<precision)
    return 0;
  return p>0?1:-1;
}

static inline double det(x1,y1,x2,y2)
     double x1,y1,x2,y2;
{
  return x1*y2-x2*y1;
}

static inline double cross(A,B,P)
     point A,B,P;
{
  return det(B.x-A.x,B.y-A.y,P.x-A.x,P.y-A.y);
}

static inline int check(A,B,C,D)
     point A,B,C,D;
{
  return (dblcmp(cross(A,B,C)) * dblcmp(cross(A,B,D)) <=0);
}

double intersection(point A,point B,point C,point D){
    double area1 = cross(A,B,C);
    double area2 = cross(A,B,D);
    int c = dblcmp(area1);
    int d = dblcmp(area2);
    if(c*d<0){
      return (area2*C.x-area1*D.x)/(area2-area1);
    }
    else if(c*d==0){
      return (c==0)?(C.x):(D.x);
    }
    else
      return -inf;
}

int main(){
  int i,j,k,pointNum=0,flag=0;
  double max_x=-inf;
  point*up,*down;
  scanf("%d",&pointNum);
  while(pointNum!=0){
    max_x=-inf;
    up = (point*)malloc(sizeof(point)*(pointNum+1));
    down = (point*)malloc(sizeof(point)*(pointNum+1));
    for(i=1;i<=pointNum;i++){
      scanf("%lf %lf",&(up[i].x),&(up[i].y));
      down[i].x = up[i].x;
      down[i].y = up[i].y-1;
    }
    flag = 0;
    for(i=1;i<=pointNum;i++){
      for(j=1;j<=pointNum;j++){
	for(k=1;k<=pointNum && check(up[i],down[j],up[k],down[k])!=0 ;k++);
	if(k>pointNum) {flag = 1;break;}
	else if(k>max(i,j)){
	  double tmp = intersection(up[i],down[j],up[k],up[k-1]);
	  max_x = (max_x>tmp)?max_x:tmp;
	  tmp = intersection(up[i],down[j],down[k],down[k-1]);
	  max_x = (max_x>tmp)?max_x:tmp;
	}
      }
    if(flag == 1) break;
    }
    if(flag == 1) printf("Through all the pipe.\n");
    else printf("%.2f\n",max_x);
    scanf("%d",&pointNum);
  }
  free(up);
  free(down);
  return 0;
}
