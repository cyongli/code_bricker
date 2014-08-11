#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x) {
    	string s;
		do{
			s.append(std::to_string(x%10));
		}while((x/=10)!=0);
		int start = 0;
		int end = s.size()-1;
		for(int i=0;i<s.size()/2;i++){
			if(s[start]!=s[end]) return false;
			++start;
			--end;
		}
		return true;
    }
}; 

int main(int argc, char *argv[]){
	Solution sol;
	cout << sol.isPalindrome(stoi(argv[1])) << endl;
}
