/*题目大意：去掉有序数组里面的重复元素，并得到最终的数组
 * 每次都找到重复元素的最后一个，将它放在指定位置
 */

#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i,j,end=-1,dup=1;
        for(i=0;i<n;){
            for(j=i+1;j<n && A[j]==A[i];j++) dup++;
			if(dup>=2){
				A[++end] = A[j-2];
            	A[++end] = A[j-1];
			}
			else A[++end] = A[j-1];
            i=j;
			dup = 1;
        }
		for(int i=0;i<=end;i++){
			cout << A[i] << endl;
		}
        return end+1;
    }
};

int main(int argc, char *argv[]){
	int A[]={1,1,1,2,2,3};
	Solution sol;
	sol.removeDuplicates(A,6);
}
