/*stupid implemention
 * 用组合法进行实现
 * 找出所有的合适位置进行划分
 */
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
private:
	vector<string> validBreaks;
public:
	void print(string &list,int n,bool *flags){
		int i=0,j=0;
		for(i=0;i<n;i++){
			if(flags[i]==true){
				cout << list.substr(j,i+1-j) << "\x20";
				j = i+1;
				//cout << list[i] << "\x20";
			}
		}
		cout << list.substr(j,list.length()-j) << endl;
	}

	void isValidBreak(string &list,int n,bool *flags,unordered_set<string> &dict){
		int i=0,j=0,k=0;
		for(i=0;i<n;i++){
			if(flags[i]==true){
				//cout << list.substr(j,i+1-j) << "\x20";
				if(dict.find(list.substr(j,i+1-j))==dict.end()){
					if(i==n-1) {j=i+1; goto L;}
					for(j=n-1,k=n-1;j>=i+1;j--){
						if(flags[j]==true){
							std::swap(flags[j],flags[k]);
							--k;
						}
					}			
					//flags[i+1]=false;
					goto L;
				}		
				j = i+1;
			}
		}
	
		if(dict.find(list.substr(j,list.length()-j)) != dict.end()){
			i=0,j=0;
			string word;
			for(i=0;i<n;i++){
				if(flags[i]==true){
					word.append(list.substr(j,i+1-j)+" ");
					j = i+1;
				}
			}
			word.append(list.substr(j,list.length()-j));
			validBreaks.push_back(word);
		}
	
		L: return;
	}	

	/*0,1交换法*/
	void comb(string &list,int n,bool *flags,unordered_set<string> &dict){
		isValidBreak(list,n,flags,dict);
		int i,j,k;
		for(i=n-1;i>0;i--){
			if(flags[i]==false && flags[i-1]==true){
				std::swap(flags[i],flags[i-1]);
				for(j=i+1,k=i+1;j<n;j++){
					if(flags[j]==true){
						std::swap(flags[j],flags[k]);
						++k;
					}
				}
				isValidBreak(list,n,flags,dict);
				i=n;
			}
		}
	}

    vector<string> wordBreak(string &seq, unordered_set<string> &dict){
		bool *flags = new bool[seq.length()-1];
		memset(flags,0,sizeof(flags)*(seq.length()-1));
		int i,j;
		isValidBreak(seq,seq.length(),flags,dict);
       	for(i=1;i<seq.length();i++){
			for(j=0;j<i;j++) flags[j]=true;
			for(j=i;j<seq.length()-1;j++) flags[j]=false;
			//cout << "i is: " << i << endl;
			comb(seq,seq.length()-1,flags,dict);
		} 
		return validBreaks;
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
