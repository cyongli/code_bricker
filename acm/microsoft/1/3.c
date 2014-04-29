#include<stdio.h>
#include<math.h>

typedef struct{
  double x;
  double y;
} coordinate;

coordinate citizen[100000];

int main(){
  int tstNum;
  scanf("%d",&tstNum);
  int citzen_Num=0;
  int i=0,j=0;
  double low,high;    
  double a1,a2;
  double sum1=0;
  double sum2=0;
  double ypow2;
  for(i=1;i<=tstNum;i++){
    scanf("%d",&citzen_Num);
    for(j=1;j<=citzen_Num;j++)
      scanf("%lf %lf",&citizen[j-1].x,&citizen[j-1].y);
    low = citizen[0].x;
    high = citizen[0].x;
    for(j=1;j<citzen_Num;j++){
      if(citizen[j].x<low)
	low = citizen[j].x;
      else if(citizen[j].x>high)
	high = citizen[j].x;
    }
    while(high-low>=1e-7){
      a1=(high-low)/3+low;
      a2=(high-low)*2/3+low;
      sum1 = 0;
      sum2 = 0;
      for(j=0;j<citzen_Num;j++){
	ypow2 = pow(citizen[j].y,2);
	sum1 += sqrt(pow(citizen[j].x-a1,2)+ypow2);
	sum2 += sqrt(pow(citizen[j].x-a2,2)+ypow2);
      }
      if(sum1<sum2){
	high = a2;
      }
      else {
	low = a1;
      }
    }
    printf("Case %d: %.6f\n",i,low);
  }
  return 0;
}
