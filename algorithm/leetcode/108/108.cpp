/*
题意:数组里面存储的每一个位置可以跳转的最大距离，就跳到末尾的最小步数
思路:从i开始，i~i+A[i]之间的步数为steps[i]+1。
     如果i~i+A[i]之间有一个j,j+A[j]大于n-1,步数为steps[j]+1;
     如果j==n-1,步数为step[j]
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int *steps = new int[n];
        steps[0]=0;
        for(int i=1;i<n;++i) steps[i]=std::numeric_limits<int>::max();
        for(int i=0;i<n;++i){
            for(int j=i;j<=i+A[i] && j<n;++j){
                steps[j] = (steps[j]<1+steps[i]) ? steps[j] : (steps[i]+1);
                if(j==n-1) return steps[j];
                if(j+A[j]>=n-1) return steps[j]+1;
            }
        }
        return steps[n-1];
    }
};

int main(int argc, char *argv[]){
	
	return 0;
}
