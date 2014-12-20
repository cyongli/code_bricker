/*寻找第k个排列数
 *在pos位置上的数字开头的排列有(n-pos)!个 
 *可以根据这样去选择数字
 * */
#include<iostream>
using namespace std;

class Solution {
private:
	int *fact;
public:
	void factorial(int *fact,int n){
		for(int i=0;i<n;i++) fact[i]=i;
		fact[0]=1;
		for(int i=1;i<=n-1;i++){
			fact[i] *= fact[i-1];
		}
		for(int i=0;i<=n-1;i++){
			cout << i << "!=" << fact[i]<< endl;
		}
	}

    string getPermutation(int n, int k) {
        fact = new int[n];
		factorial(fact,n);
		string nextPerm;
		bool *access = new bool[n+1];
		for(int i=0;i<=n;i++) access[i]=false;
		int pos = 0,i,j;
		for(i=1;i<=n;i++){
			pos = 1+(k-1)/fact[n-i];
			for(j=1;j<=n;j++){
				if(access[j]==false && (--pos)==0){
					nextPerm.append(std::to_string(j));
					access[j]=true;
					break;
				}
			}
			pos = 1+(k-1)/fact[n-i];
			k = k-(pos-1)*(fact[n-i]);
		}		
		return nextPerm;		
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	cout << sol.getPermutation(stoi(argv[1]),stoi(argv[2])) << endl;
	return 0;
}
