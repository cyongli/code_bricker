#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

class Solution {
private:
    vector<vector<string>> ret;
public:
    bool isValid(char **a, int n ,int pos, int col){
	for(int i=0;i<col;i++){
	    for(int j=0;j<n;j++){
		if(a[j][i]=='Q' && (j==pos || abs(i-col)==abs(pos-j))) return false;
	    }
	}
	return true;
    }

    void dfs(char **a, int n, int pre, int col){
	if(col==n){
	    vector<string> one;
	    for(int i=0;i<n;i++){
		string s(a[i]);
		one.push_back(s);
	    }
	    ret.push_back(one);
	    one.clear();
	    return ;
	}
	for(int i=0;i<n;i++){
	    if(i!=pre && abs(i-pre)!=1 && isValid(a,n,i,col)){
		a[i][col]='Q';
		dfs(a,n,i,col+1);
		a[i][col]='.';
	    }
	}
    }

    vector<vector<string> > solveNQueens(int n) {
        char **a = new char*[n];
	for(int i=0;i<n;i++) a[i] = new char[n+1];
	for(int i=0;i<n;i++)
	    memset(a[i],46,n);
	for(int i=0;i<n;i++){
	    printf("%s\n",a[i]);
	}
	for(int i=0;i<n;i++){
	    a[i][0]='Q';
	    dfs(a,n,i,1);
	    a[i][0]='.';
	}
	print(ret);
	return ret;
    }
    
    void print(vector<vector<string>> &ret) const{
	vector<vector<string>>::iterator out;
	for(out=ret.begin(); out!=ret.end(); out++){
	    vector<string>::iterator in;
	    for(in=(*out).begin(); in!=(*out).end(); in++){
		cout << (*in) << endl;
	    }
	    cout << endl;
	}
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    sol.solveNQueens(stoi(argv[1]));
    return 0;
}
