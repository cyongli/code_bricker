#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if(s.size()==0) return true;
 		int start = 0;
		int end = s.size()-1;
		for(int i=0;i<s.size()-1 && start<end;i++){
			for(;start<end && std::isalpha(s[start])==false && std::isdigit(s[start])==false;++start);
			for(;end>start && std::isalpha(s[end])==false && std::isdigit(s[end])==false;--end);
			if(s[start]!=s[end] && s[start]!=s[end]+32 && s[start]!=s[end]-32){
				return false;
			} 
			++start;
			--end;
		}  	    
		return true;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string s(argv[1]);
	cout << s << endl;
	cout << sol.isPalindrome(s) << endl;
	return 0;
}
