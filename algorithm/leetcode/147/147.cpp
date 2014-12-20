#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalin(string s){
		int start = 0;
		int end = s.size()-1;
		for(int i=0;i<s.size()/2;++i){
			if(s[start]!=s[end]) return false;
			++start;
			--end;
		}
		return true;
	}
	
    string longestPalindrome(string s) {
		int len = s.size();
    	int *count = new int[len];
		for(int i=0;i<len;i++) count[i]=1;
		for(int i=1;i<len;i++){
			if((i-1-count[i-1])>=0 && s[i]==s[i-1-count[i-1]]) {
				count[i]=count[i-1]+2;
				continue;	
			}
			for(int j=i-count[i-1];j<=i-1;j++){
				if(isPalin(s.substr(j,i-j+1))){
					count[i] = i-j+1;
					break;
				}
			}
		}	
		int p=0;
		int max=count[0];
		for(int i=1;i<len;i++){
			if(count[i]>max){
				max=count[i];
				p = i;
			}
		}
		return s.substr(p+1-count[p],count[p]);
    }
};

int main(int argc, char *argv[]){
	string s(argv[1]);
	Solution sol;
	cout << sol.longestPalindrome(s) << endl;
	return 0;
}
