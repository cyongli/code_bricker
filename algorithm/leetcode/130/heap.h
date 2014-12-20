#include<iostream>
#include<cassert>
using namespace std;
class heap{
 private:
    int *h;
    int maxSize;
    int n;
    void siftdown(int pos){
	while(!isLeaf(pos)){
	    int j = leftChild(pos);
	    int rc = rightChild(pos);
	    if((rc<n) && (h[rc]<h[j])){
		j = rc;
	    }
	    if(h[pos]>h[j]){
		std::swap(h[pos],h[j]);
	    }
	    pos = j;
	}
    }
 public:
    heap(int maxSize){
	this->maxSize = maxSize;
	n = 0;
	h = new int[this->maxSize];
    }
    int size() const
    { return n; }
    bool isLeaf(int pos) const
    { return (pos>=n/2) && (pos<n); }
    int leftChild(int pos) const
    { return 2*pos+1; }
    int rightChild(int pos) const
    { return 2*pos+2; }
    int parent(int pos) const
    { return (pos-1)/2; }
    void buildHead(){
	for(int i=n/2-1;i>=0;--i)
	    siftdown(i);
    }
    void insert(const int &it){
	assert((n<maxSize,"h is full"));
	int curr = n++;
	h[curr]=it;
	while((curr!=0) && (h[curr]<h[parent(curr)])){
	    std::swap(h[curr],h[parent(curr)]);
	    curr = parent(curr);
	}
    }
    int removefirst(){
	assert((n>0, "h is empty"));
	swap(h[--n],h[0]);
	if(n!=0) siftdown(0);
	return h[n];
    }
    int remove(int pos){
	assert(((pos>=0) && (pos<n), "Bad position"));
	if(pos==(n-1)) n--;
	else{
	    swap(h[pos],h[--n]);
	    while((pos!=0) && (h[pos]<h[parent(pos)])){
		std::swap(h[pos],h[parent(pos)]);
		pos = parent(pos);
	    }
	    if(n!=0) siftdown(pos);
	}
	return h[n];
    }
    void print(){
	for(int i=0;i<n;i++){
	    cout << h[i] << endl;
	}
    }
};
