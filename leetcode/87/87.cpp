#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()==0) return b;
        if(b.size()==0) return a;
        int i,j,carry=0,tmp=0,jj=0;
        string ret;
        for(i=a.size()-1,j=b.size()-1; i>=0 || j>=0; --i,--j){
            if(i>=0 && j>=0)
                tmp = carry+(a[i]-'0')+(b[j]-'0');
            else if(i>=0)
                tmp = carry+(a[i]-'0');
            else tmp = carry+(b[j]-'0');
            if(tmp>1){
                carry = 1;
                ret.push_back((tmp%2)+'0');
            }
            else {
                carry = 0;
                ret.push_back(tmp+'0');
            }
        }
		if(carry==1) ret.push_back(carry+'0');
		for(i=0;i<ret.size()/2;i++){
			std::swap(ret[i],ret[ret.size()-i-1]);
		}
		return ret;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string a(argv[1]);
	string b(argv[2]);
	cout << sol.addBinary(a,b) << endl;
	return 0;
}
