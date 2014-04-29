
/*
  问题描述:建一个围绕城堡的城墙要求砖的用量尽量少，且城墙距离城堡的距离不能少于指定值
  解题思路:结果为城堡多边形的凸包距离加上半径为距离最小值的圆的周长        
*/

#include<stdio.h>
#include<math.h>

typedef struct{
  int x;
  int y;
}point;

point v[1000],res[1000];

void swap(point * v1,point *v2){
  point tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}

int multi(point v1,point v2,point v0){
  /*向量(v1-v0)与(v2-v0)的叉积*/
  return (v1.x-v0.x)*(v2.y-v0.y)-(v2.x-v0.x)*(v1.y-v0.y);
}

int dis(point a,point b){
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int cmp(point a,point b){
  /*等于1说明b在a的左边,b大*/
  if(multi(a,b,v[0])>0)
    return 1;
  else if(multi(a,b,v[0])==0 && dis(b,v[0])>dis(a,v[0]))
    return 1;
  else return 0;
}

int partition(point v[],int p,int r){
  point key = v[r];
  int i,j;
  for(i=p-1,j=p;j<=r-1;j++){
    if(cmp(v[j],key)==1){
      i++;
      swap(&v[i],&v[j]);
    }
  }
  swap(&v[i+1],&v[r]);
  return i+1;
}

void qsort(point v[],int p,int r){
  if(p<r){
    int q = partition(v,p,r);
    qsort(v,p,q-1);
    qsort(v,q+1,r);
  }
}

int main(){
  int n,l;
  scanf("%d %d",&n,&l);
  int i;
  for(i=0;i<n;i++){
    scanf("%d %d",&(v[i].x),&(v[i].y));
    if(v[i].y<v[0].y || (v[i].y==v[0].y && v[i].x<v[0].x))
       swap(&v[i],&v[0]);
  }
  qsort(v,1,n-1);
  int top=-1;
  res[++top]=v[0];
  res[++top]=v[1];
  res[++top]=v[2];
  for(i=3;i<n;i++){
    while(top>0 && multi(res[top],v[i],res[top-1])<0) top--;
    res[++top]=v[i];
  }
  double ans = 0;
  for(i=1;i<=top;i++)
    ans += sqrt((double)dis(res[i],res[i-1]));
  ans += sqrt((double)dis(res[top],res[0]));
  ans += 2*3.1415926*l;
  printf("%d\n",(int)(ans+0.5));
}
