#include<iostream>
#include<cassert>
using namespace std;

template<typename type,typename Comp>
class minHeap{
/*实现过程中的pos代表的都是实际在数组中的位置*/
 private:
    type *heap;
    int maxSize;
    int n;
    void siftdown(int pos){
	while(!isLeaf(pos)){
	    int j = leftChild(pos);
	    int rc = rightChild(pos);
	    if((rc<n) && Comp::prior(heap[rc],heap[j]))
		j = rc;
	    if(Comp::prior(heap[j],heap[pos]))
		std::swap(heap[pos],heap[j]);
 	    pos = j;
	}
    }
 public:
    minHeap(int max):maxSize(max){
	n = 0;
	heap = new type[maxSize];
    }
    ~minHeap() { delete [] heap;}
    minHeap(const minHeap& ) = delete;
    minHeap& operator=(const minHeap& ) = delete;
    inline int size() const { return n;}
    inline bool empty() const { return n==0;}
    inline int isLeaf(int pos) const { return (pos>=n/2) && (pos<n);}
    inline int leftChild(int pos) const { return 2*pos+1;}
    inline int rightChild(int pos) const { return 2*pos+2;}
    inline int parent(int pos) const { return (pos-1)/2;}
    int insert(type it){
	assert((n<maxSize,"heap is full"));
	int curr = n++;
	heap[curr] = it;
	while((curr!=0) && Comp::prior(heap[curr],heap[parent(curr)]) ){
	    std::swap(heap[curr],heap[parent(curr)]);
	    curr = parent(curr);
	}
    }
    type removeFirst(){
	assert((n>0,"heap is empty"));
	std::swap(heap[0],heap[--n]);
	if(n!=0) siftdown(0);
	return heap[n];
    }
    type remove(int pos){
	assert((pos>=0 && pos<n,"Bad position"));
	std::swap(heap[pos],heap[--n]);
	if(pos==n) return heap[n];
	while((pos!=0) && Comp::prior(heap[pos],heap[parent(pos)]) ){
	    std::swap(heap[pos],heap[parent(pos)]);
	    pos = parent(pos);
	}
	if(n!=0) siftdown(pos);
	return heap[n];
    }
    void print(){
	for(int i=0;i<n;i++){
	    cout << heap[i] << endl;
	}
    }
};

