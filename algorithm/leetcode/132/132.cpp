#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isMatch(char a, char b){
		if(a=='(' && b==')') return true;
		else if(a=='[' && b==']') return true;
		else if(a=='{' && b=='}') return true;
		else return false;
	}

    bool isValid(string s) {
        std::stack<char> bracket;
        for(int i=0;i<s.size();i++){
            if(bracket.empty() || !isMatch(bracket.top(),s[i])){
                bracket.push(s[i]);
            }
            else if(isMatch(bracket.top(),s[i])){
                bracket.pop();
            }
        }
        return bracket.empty();
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string s(argv[1]);
	cout << sol.isValid(s) << endl;
	return 0;
}
