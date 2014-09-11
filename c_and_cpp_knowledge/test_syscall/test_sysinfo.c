#include<stdio.h>
#include<sys/sysinfo.h>

int main(){
  struct sysinfo info;
  sysinfo(&info);
  printf("%ld\n",info.totalram);
  printf("%ld\n",info.freeram);
  printf("%ld\n",info.sharedram);
  printf("%ld\n",info.bufferram);
  printf("%ld\n",info.totalswap);
  printf("%ld\n",info.freeswap);
  printf("%d\n",info.mem_unit);
  return 0;
}
