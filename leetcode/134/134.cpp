#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
	vector<string> result;
	string tel[10];
public:
	void init(){
		tel[2]="abc";
		tel[3]="def";
		tel[4]="ghi";
		tel[5]="jkl";
		tel[6]="mno";
		tel[7]="pqrs";
		tel[8]="tuv";
		tel[9]="wxyz";
	}

	void dfs(int start,string &seq,string &digits){
		if(start==digits.size()){
			result.push_back(seq);
			return;
		}
		for(int j=0;j<tel[stoi(digits.substr(start,1))].size();j++){
			seq.push_back(tel[stoi(digits.substr(start,1))][j]);
			dfs(start+1,seq,digits);
			seq.pop_back();
		}	
	}

    vector<string> letterCombinations(string digits) {
    	//cout << digits << endl;	    
		init();
		string seq;	
		dfs(0,seq,digits);
		return result;
    }
	
	void print(){
		vector<string>::iterator it = result.begin();
		for(;it!=result.end();it++){
			cout << *it << endl;
		}
	}
	
};

int main(int argc, char *argv[]){
	string digits(argv[1]);
	Solution sol;
	sol.letterCombinations(digits);
	sol.print();
	return 0;
}
