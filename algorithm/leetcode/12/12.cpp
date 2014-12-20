#include<iostream>
#include<vector>
#include<fstream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
  vector<string> midres;
  vector<string> res;
  vector<bool> *dp;
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    int len = s.length();
    
    dp = new vector<bool>[len];
    for(int i=0; i<len; ++i){
      for(int j=i; j<len; ++j){
        if(dict.find(s.substr(i, j-i+1))!=dict.end()){
          dp[i].push_back(true);	  //第二维的下标实际是:单词长度-1
        }else{
          dp[i].push_back(false);	 //数组第二维用vector,size不一定是n,这样比n*n节省空间
        }
      }
    }
    func(s, len-1);
    return res;
  }
  
  void func(const string &s, int i){
    if(i>=0){
      for(int j=0; j<=i; ++j){
        
        if(dp[j][i-j]){ //注意此处的第二个下标是 i-j，不是i,因为数组的第二维长度是不固定的,第二维的下标实际是单词长度-1
        
          midres.push_back(s.substr(j, i-j+1));
          func(s, j-1);
          midres.pop_back();  //继续考虑for循环的下一个分段处
        }
      }
      return;
    }
    else{
      string str;
      for(int k=midres.size()-1; k>=0; --k){  //注意遍历的顺序是倒序的
        str += midres[k];   //注意此处是k,不是i
        if(k>0)
          str += " ";
      }
      res.push_back(str);
      return;
    }
  }
};

int main(int argc, char *argv[]){
	unordered_set<string> dict;
	string word;
	ifstream fi(argv[1],ios::in);
	for(int i=0;i<stoi(argv[2]);i++){
		fi >> word;
		dict.insert(word);
	}
	string seq(argv[3]);

	Solution sol;
	vector<string> wordBreaks = sol.wordBreak(seq,dict);

	vector<string>::const_iterator it = wordBreaks.begin();
	//cout<<wordBreaks.size()<<endl;
	for(;it!=wordBreaks.end();it++){
		cout << *it << endl;
	}
	return 0;
}
