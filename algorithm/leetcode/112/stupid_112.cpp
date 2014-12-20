/*题目大意:寻找数组中第一个没有出现的正整数
 *方法:如果数组中存在1，就把数组中全部元素都减去1，
       直到结束。是一个伪多项式算法
 */

#include<iostream>
using namespace std;

class Solution {
public:
    bool hasOne(int A[],int n){
        for(int i=0;i<n;i++){
            if(A[i]==1) return true;
        }
        return false;
    }

    int firstMissingPositive(int A[], int n) {
        int loop = 0;
        while(hasOne(A,n)){
            loop += 1;
            for(int j=0;j<n;j++) A[j] -= 1;
        }
        return loop+1;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	int A[]={1,2,1213};
	cout << sol.firstMissingPositive(A,3) << endl;
	return 0;
}
