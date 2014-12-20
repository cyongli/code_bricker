#include<iostream>
#include<typeinfo>
using namespace std;

int main(){
  string a = "ad";
  cout<<a<<endl;
  cout<<typeid(a).name()<<endl;
  return 0;
}
