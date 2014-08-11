#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
private:
	vector<string> ipSet;
	vector<int> posSet;
public:
	Solution() {}

	bool isValidIp(string tokens[]){
		bool isValid = true;
		for(int i=0;i<=3;i++){
			if(tokens[i].length()>3 || stoi(tokens[i])>255){
				isValid = false;
				goto L;
			} else if(tokens[i][0]=='0' && tokens[i].length()!=1){
				isValid = false;
				goto L;
			}
		}
		L: return isValid;
	}

	void comb(int *list,int n,int r,int subset[]){
		if(r==0){
			for(int i=0;i<3;i++){
				/*把所有合理的组合数插入到posSet vector中，三三一组*/
				posSet.push_back(subset[i]);
			}
			 return;
		}
		for(int i=n;i>=r;i--){
			subset[r-1] = list[i-1];
			comb(list,i-1,r-1,subset);
		}
	}

	void mysplit(string &s, string tokens[], int pos1, int pos2, int pos3){
		tokens[0] = s.substr(0,pos1);
		tokens[1] = s.substr(pos1,pos2-pos1);
		tokens[2] = s.substr(pos2,pos3-pos2);
		tokens[3] = s.substr(pos3,s.length()-pos3);
	}

	vector<string> restoreIpAddresses(string s){
		if(s.length()<4 || s.length()>12){
			/*ip地址的长度在4~12之间*/
			return ipSet;
		}
		int subset[3];
		/*pos数组记录可以序列的有效分割的位置*/
		int *pos = new int[s.length()];
		for(int i=1;i<=s.length()-1 && (pos[i-1]=i);i++);
		/*从pos array中选取3个位置，作为字符序列的分割点*/
		comb(pos,s.length()-1,3,subset);
		vector<int>::const_iterator it = posSet.begin();
		string tokens[4];
		for(;it!=posSet.end();it+=3){
			mysplit(s,tokens,(*it),*(it+1),*(it+2));
			if(isValidIp(tokens)){
				string ip;
				for(int i=0;i<3;i++){
					ip.append(tokens[i]+".");
				}
				ip.append(tokens[3]);
				ipSet.push_back(ip);
			}
		}				
		return ipSet;
	}
		
	void print(){
		vector<string>::const_iterator it = ipSet.begin();
		for(;it!=ipSet.end();it++){
			cout << (*it) << endl;
		}
	}
	
};

int main(int argc, char* argv[]){
	Solution sol;
	sol.restoreIpAddresses(argv[1]);
	sol.print();
	return 0;
}
