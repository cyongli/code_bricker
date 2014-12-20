#include<iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
		if(s.length()==0) return 0;
    	int len=s.length();
		int **matrix = new int*[len];
		for(int i=0;i<len;i++){
			matrix[i] = new int[len];
		}	
		/*cuts[i]表示包含从i开始,包含s[i]的最小回文分割数*/
		int *cuts = new int[len+1];
		/*初始化cuts里面的值为最坏情况的值*/
		for(int i=0;i<=len;i++) cuts[i]=len-i;
		int *pos = new int[len];
		/*pos用来记录分割的位置*/	
		for(int i=0;i<len;i++) pos[i]=i+1;
		/*dp过程*/
		for(int i=len-1;i>=0;--i){
			for(int j=i;j<len;j++){
				if(((j-i)<2 && s[i]==s[j]) || (s[i]==s[j] && matrix[i+1][j-1]==true)){
					matrix[i][j]=true;
					if(cuts[i]>cuts[j+1]+1){
						cuts[i] = cuts[j+1]+1;
						pos[i]=j+1;
					}
				}
			}
		}
		for(int i=0;i<len;i++){
			cout << s.substr(i,pos[i]-i) << endl;
			i = pos[i]-1;
		}
		return cuts[0]-1;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string s(argv[1]);
	cout << "min cuts num:" << sol.minCut(s) << endl;
	return 0;
}
