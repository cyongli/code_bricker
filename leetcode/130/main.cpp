#include<iostream>
#include<ctime>
#include "minHeap.h"
using namespace std;

class Comp{
public:
    static bool prior(int r1,int r2){
	return r1<r2;
    }
};

int main(int argc, char *argv[]){
    minHeap<int,Comp> heap(stoi(argv[1]));
    srand(time(NULL));
    for(int i=0;i<stoi(argv[1]);i++){
	heap.insert(rand()%100);
    }
    //heap.print();
    //cout << endl;
    int len = heap.size();
    for(int i=0;i<len;i++){
	cout << heap.removeFirst() << endl;
	//heap.print();
	//cout << endl;
    }
    return 0;
}
