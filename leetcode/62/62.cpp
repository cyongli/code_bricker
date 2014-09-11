#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string &s, int start, int end){
        if(start<0) return false;
        int num = stoi(s.substr(start,end-start+1));
        if(num>=10 && num<=26) return true;
        else return false;
    }

    int numDecodings(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        int *num = new int[s.size()];
        for(int i=0;i<s.size();++i) num[i] = 1;
        for(int i=1;i<s.size();++i){
            if(isValid(s,i-1,i) && !isValid(s,i-2,i-1)){
                num[i] = 2*num[i-1];
            }
            else if(isValid(s,i-1,i) && isValid(s,i-2,i-1)){
                num[i] = num[i-1] + num[i-2];
            }
            else num[i] = num[i-1];
        }
        return num[s.size()-1];
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string s(argv[1]);
	cout << sol.numDecodings(s) << endl;
	return 0;
}
