静态链接库
  gcc -c ctest1.c ctest2.c
  ar -rsv libctest.a ctest1.o ctest2.o
  gcc prog.c -o prog -L. -lctest
  ./prog

动态链接库
  程序执行时动态链接的搜索方式顺序
  LD_LIBRARY_PATH -> ld.so.conf -> /lib, /usr/lib/
  可以通过如下方式进行
    (1)  export LD_LIBRARY_PATH=
    (2)  lddconfig `pwd`
    (3)  修改ld.so.conf
    (4)  将程序拷贝到/lib, /usr/lib下面
  前两种方式其实是直接修改/etc/ld.so.cache文件，因为这个是缓存了搜索路径

  动态链接库有两种使用方式
    1. 程序运行时动态链接
      gcc -o libctest.so -shared -fPIC ctest1.c ctest2.c
      gcc prog.c -o prog -L. -lctest
      编译时的-lctest标记GCC驱动程序在连接阶段引用动态链接库libctest.so
      export LD_LIBRARY_PATH=.
      ./prog
    
    2.动态加载在程序中使用他们
	  此种方法主要是通过dlfcn.h中的函数进行操作
	  dlsym, dlopen, dlclose等函数进行
      gcc -o libctest.so -shared -fPIC ctest1.c ctest2.c
      gcc -o prog_2 prog_2.c -rdynamic -ldl
      ./prog_2
