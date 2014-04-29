#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *substr(const char *s,int n1,int n2)
{
  char *sp=malloc(sizeof(char)*(n2-n1+2));
  int i,j=0;
  for (i=n1; i<=n2; i++) {
    sp[j++]=s[i];
  }
  sp[j]=0;
  return sp;
}

double h_s(char* digit){
  int len = strlen(digit);
  char* fh = (char*)malloc(sizeof(char)*5);
  fh = substr(digit,len-2,len-1);
  if(strcmp(fh,"dm")==0)
     return atof(substr(digit,0,len-3))*100;
  else if(strcmp(fh,"cm")==0)
    return atof(substr(digit,0,len-3))*10;
  else if(strcmp(fh,"mm")==0)
    return atof(substr(digit,0,len-3));
  else if(strcmp(fh,"um")==0)
    return atof(substr(digit,0,len-3))/1000;
  else if(strcmp(fh,"nm")==0)
    return atof(substr(digit,0,len-3))/1000000;
  else return atof(substr(digit,0,len-2))*1000;

}

int main(){
  int tstNum,i;
  scanf("%d",&tstNum);
  char focal[20];
  char ccd[20];
  char px[20];
  double i_focal;
  double i_ccd;
  double i_px;
  char a[5];
  while(++i <= tstNum){
    scanf("%s %s %s",focal,ccd,px);
    i_focal = h_s(focal);
    i_ccd = h_s(ccd);
    i_px = atof(substr(px,0,strlen(px)-3));
    printf("Case %d: %.2fpx\n",i,(i_focal*i_px)/i_ccd);
  }
  return 0;
}
