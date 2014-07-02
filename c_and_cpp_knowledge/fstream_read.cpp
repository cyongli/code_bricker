#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
  char a[1024];
  ifstream table("table.tbl",ios::in | ios::out);
  table.seekg(0,table.end);
  int length = table.tellg();
  table.seekg(0,table.beg);
  table.read(a,length);
  cout<<a<<endl;
  string b;
  string c;
  int i = 0;int j = 0;
  int k = 0;
  while(a[k] != 0x0){
    while(a[i++] != 0x20);
    b.append(a,k,i-k-1);
    j = i;
    while(a[j++] != 0xa);
    //cout<<i<<"\x20"<<j<<endl;
    c.append(a,i,j-i-1);
    cout<<b<<c<<endl;
    k = j;
    i = j;
    b.clear();
    c.clear();
  }
  return 0;
}

