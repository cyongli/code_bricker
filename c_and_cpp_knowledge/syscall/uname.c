#include<stdio.h>
#include<sys/utsname.h>

int main(){
  struct utsname unameData;
  uname(&unameData);
  printf("%s\n",unameData.sysname);
  printf("%s\n",unameData.nodename);
  printf("%s\n",unameData.release);
  printf("%s\n",unameData.version);
  printf("%s\n",unameData.machine);
  printf("%s\n",unameData.__domainname);
  return 0;
}
