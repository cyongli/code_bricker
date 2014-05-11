/*此程序是用system call得到磁盘的使用情况*/

#include<stdio.h>
#include<sys/statfs.h>

int main(int argc,char*argv[]){
  struct statfs disk_info;
  char* path="/";//可为设备名,文件目录
  statfs(path,&disk_info);
  printf("f_type:%d\n",disk_info.f_type);
  printf("f_bsize:%d\n",disk_info.f_bsize);
  printf("f_blocks:%ld\n",disk_info.f_blocks);
  printf("f_bfree:%ld\n",disk_info.f_bfree);
  printf("f_bavail:%ld\n",disk_info.f_bavail);
  printf("f_files:%ld\n",disk_info.f_files);
  printf("f_ffree:%ld\n",disk_info.f_ffree);
  return 0;
}
