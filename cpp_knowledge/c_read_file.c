#include<stdio.h>


int main(int argc,char*argv[]){
  FILE* file = fopen("table.tbl","a+");
  char username[20];
  int age;
  while(!feof(file)){
    if(feof(file)) break;
    fscanf(file,"%s",username);
    fscanf(file,"%d",&age);
    printf("%s %d\n",username,age);
  }
  fclose(file);
  return 0;
}
