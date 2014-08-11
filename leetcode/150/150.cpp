/*题目意思是：求两个有序数组合并后的中位数，如果是偶数，则
 *是两个中位数的均值
 *
 *如果直接中两个数组的中位数进行比较，会产生很多的边界问题*
 *所以把题目换成求合并后的数组的第k小的元素
 */

#include<iostream>
using namespace std;

class Solution {
public:
	int findKth(int A[],int m,int B[],int n,int k){
		/*寻找两个有序数组中的第k大小的值*/
		if(m>n) return findKth(B,n,A,m,k);
		if(m==0) return B[k-1];
		if(k==1) return std::min(A[0],B[0]);
		int pa = std::min(k/2,m);
		int pb = k-pa;
		if(A[pa-1] < B[pb-1]){
			return findKth(A+pa,m-pa,B,n,k-pa);
		}
		else if(A[pa-1] > B[pb-1]){
			return findKth(A,m,B+pb,n-pb,k-pb);
		}
		else return A[pa-1];
	}


	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m+n;
		if(total & 0x1){
			return findKth(A,m,B,n,total/2+1);
		}
		else{
			return ((double)findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2;
		}
    }
};

int main(int argc, char *argv[]){
	int A[]={1,2};
	int B[]={1,2};
	Solution sol;
	cout << sol.findMedianSortedArrays(A,2,B,2) << endl;
	return 0;
}
