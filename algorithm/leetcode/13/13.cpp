#include<iostream>
#include<fstream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    bool wordBreak(string &s, unordered_set<string> &dict) {
  		int len = s.length();
		bool *arrays = new bool[len+1];
		for(int i=0;i<len+1;i++) arrays[i]=false;
		arrays[0]=true;
		for(int i=0;i<=len;i++){
			for(int j=0;j<i;j++){
				if((arrays[j]==true) && (dict.find(s.substr(j,i-j)))!=dict.end()){
					arrays[i]=true;
					break;
				}
			}
		}
		return arrays[len];
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
	bool valid = sol.wordBreak(seq,dict);
	cout << valid << endl;
	
	return 0;
}
