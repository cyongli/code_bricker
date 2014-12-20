#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
    	vector<vector<string>> result;
		vector<string> output;
		dfs(s,0,output,result);
		vector<vector<string>>::iterator out= result.begin();
		for(;out!=result.end();out++){
			vector<string>::iterator in = (*out).begin();
			for(;in!=(*out).end();in++){
				cout << *(in) << "\x20";
			}
			cout << endl;
		}
		return result;    
    }
	
	bool isPalin(string s){
		int end = s.size()-1;
		int start = 0;
		for(int i=0;i<s.size()/2;i++){
			if(s[start]!=s[end]) return false;
			++start;
			--end;
		}
		return true;
	}

	void dfs(string &s, int start, vector<string> &output, vector<vector<string>> &result){
		if(start == s.size()){
			result.push_back(output);
			return;
		}
		for(int i=start;i<s.size();i++){
			if(isPalin(s.substr(start,i-start+1))){
				output.push_back(s.substr(start,i-start+1));
				dfs(s,i+1,output,result);
				output.pop_back();
			}
		}
	}
};

int main(int argc, char *argv[]){
	Solution sol;
	string s(argv[1]);
	sol.partition(s);
	return 0;
}
