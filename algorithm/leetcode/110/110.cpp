#include<iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		string ret;
		ret.resize(num1.size()+num2.size());
		for(int i=0;i<ret.size();i++) ret[i] = '0';
		int i,j,i1,i2,tmp,carry,jj;
		jj = carry = 0;
		for(i1=num1.size()-1;i1>=0;--i1){
			j = jj;
			for(i2=num2.size()-1;i2>=0;--i2,++j){
				tmp = (ret[j]-'0')+(num1[i1]-'0')*(num2[i2]-'0')+carry;
				if(tmp>9){
					carry = tmp/10;
					ret[j]=tmp%10+'0';
				}
				else{
					ret[j]=tmp+'0';
					carry = 0;
				}
			}
			if(carry){
				ret[j]=carry+'0';
				carry = 0;
				++j;
			}
			++jj;
		}
		ret.resize(j);
		char ch;
		for(i=0,--j;i<j;++i,--j){
			ch = ret[i];
			ret[i]=ret[j];
			ret[j]=ch;
		}
		if(ret[0]=='0') ret.resize(1);
		//else ret.resize(j);
		return ret;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	string num1(argv[1]);
	string num2(argv[2]);
	cout << sol.multiply(num1,num2) << endl;
	return 0;
}
