#include<iostream>
#include<fstream>
#include<thread>
using namespace std;

void hello(){
  ofstream savefile("/home/chaoyli/code_bricker/test_multithread/helloworld.txt");
  savefile<<"Hello Concurrent World\n";
  //chrono::milliseconds dura(1000);
  //this_thread::sleep_for(dura);
  savefile.close();
  cout<<"hello"<<endl;
}

int main(int argc,char*argv[]){
  thread t(hello);
  //t.join();
  t.detach();
  this_thread::sleep_for(chrono::seconds(1));
  //getchar();
  return 0;
}
