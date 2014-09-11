#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s, int start, int end){
        if(end >= s.size()) return false;
        if(start == end && s[start]-'0'>0 && s[start]-'0'<=9)
            return true;
        else if(start == end-1){
			int num = stoi(s.substr(start,end-start+1));
            if( num >= 10 && num <=26){ 
                return true;  
            }
        }
        else return false;
    }

    void dfs(string s, int start, int &decWays){
        if(start >= s.size()) ++decWays;
        if(isValid(s,start,start)){
            dfs(s,start+1,decWays);
        }
        if(isValid(s,start,start+1)){
            dfs(s,start+2,decWays);
        }
    }
    
    int numDecodings(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        int decWays = 0;
        dfs(s,0,decWays);
        return decWays;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string s(argv[1]);
	cout << sol.numDecodings(s) << endl;
	return 0;
}
