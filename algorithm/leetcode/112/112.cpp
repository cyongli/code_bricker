/*题目大意:寻找数组中第一个没有出现的正整数
 *方法:将数字x放在数组a[x-1]处，从头遍历寻找不满足此
 *     条件的第一个元素。
 */

#include<iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		for(int i=0;i<n;){
			if(A[i]!=(i+1) && A[i]>=1 && A[A[i]-1]!=A[i] && A[i]<=n){
				std::swap(A[i],A[A[i]-1]);
			}
			else i++;
        }
		for(int i=0;i<n;i++){
			if(A[i]!=i+1){
				return i+1;
			}
		}
        return n+1;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	int A[]={-1,-1,-1213};
	cout << sol.firstMissingPositive(A,3) << endl;
	return 0;
}
