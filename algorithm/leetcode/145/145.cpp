#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		string s = to_string(x);
		int len = s.size();
		int k = (s[0]=='-') ? 1 : 0;
		for(int i=k;i<(len+k)/2;++i){
			std::swap(s[i],s[len-i-1+k]);
		}
		return stoi(s);
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	cout << sol.reverse(stoi(argv[1])) << endl;
	return 0;
}
