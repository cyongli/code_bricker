#include<stdio.h>
#include<dlfcn.h>

void ctest1(int *);
void ctest2(int *);
void (*fn)(int *);

int main(){
  int x;
  void *handle = dlopen("./libctest.so", RTLD_LAZY);
  const char* err = dlerror();
  if (NULL != err) {
	perror("could not open shared object!");
  }
  fn = dlsym(handle, "ctest1");
  fn(&x);
  printf("ctest1 Valx=%d\n", x);
  fn = dlsym(handle, "ctest2");
  fn(&x);
  printf("ctest2 Valx=%d\n", x);
  dlclose(handle);
  return 0;
}
