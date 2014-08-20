/*
题意:每一个字母对应一个数字,
     A -> 1
     B -> 2
     ...
     Z -> 26
给定一个数字序列，求编码的总数
解法1:dfs
解法2:F(n) = F(n-1)+F(n-2), if substr(n-1,n-2),substr(n,n-1)都在序列中
      F(n) = 2*F(n-1), if substr(n,n-1)在序列中,substr(n-1,n-2)不在序列中
      F(n) = F(n-2),if substr(n-1,n-2),substr(n,n-1)都在序列中且a[n]=0
      F(n) = F(n-1）, if substr(n,n-1)在序列中,substr(n-1,n-2)不在序列中且a[n]=0
*/
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

