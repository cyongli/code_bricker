#include <iostream>
#include <limits>
using namespace std;

template<class T>
T findMax(const T* const data,const size_t numItems){
  T largest = std::numeric_limits<T>::min();
  size_t i = 0;
  for(i =0;i<numItems;i++){
    if (data[i] > largest) largest = data[i];
  }
  return largest;
}

int main(int argc,char* argv[]){
  double data[] = {1,2.9,3,4912.1,2.7,3.6};
  cout<<findMax<double>(data,6)<<endl;
  return 0;
}
