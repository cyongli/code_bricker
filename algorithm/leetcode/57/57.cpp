#include<iostream>
using namespace std;

class Solution {
public:
    int fact(int n){
        if(n==0 || n==1) return 1;
        else return n*fact(n-1);
    }

    int numTrees(int n) {
       	int divisor = 1;
		for(int i=1;i<=n/2;i++){
			divisor *= i;
		}
       	int dividend = 1;
        for(int i=2*n;i>=n+1;--i){
			//dividend *= i;
			if((i&1)==0){
				dividend *= 2;
			}
			else dividend *= i;
        }
        return dividend/(divisor*(n+1));
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	cout << sol.numTrees(stoi(argv[1])) << endl;
	return 0;
}
