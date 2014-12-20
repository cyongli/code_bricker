#include<cstdio>
#include<typeinfo>
using namespace std;

int main(int argc,char*argv[]){
  int a = 5;
  const int* b = &a;
  printf("%s\n",typeid(b).name());
  const char* c = "hello";
  printf("%s\n",typeid(c).name());
  return 0;
}
