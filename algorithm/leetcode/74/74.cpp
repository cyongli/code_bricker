#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
public:
	void add(vector<int> &s,int n,bool *flags){
		vector<int> subset;
		for(int i=0;i<n;i++){
			if(flags[i]==true){
				subset.push_back(s[i]);
			}
		}
		result.push_back(subset);	
	}	

	void comb(vector<int> &s,int n,bool *flags){
		add(s,n,flags);
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
				add(s,n,flags);
				i=n;
			}
		}
	}

	void print(){
		vector<vector<int>>::iterator out = result.begin();
		for(;out!=result.end();out++){
			vector<int>::iterator in = (*out).begin();
			for(;in!=(*out).end();in++){
				cout << *in << "\x20";
			}
			cout << endl;
		} 
	}
	
    vector<vector<int> > subsets(vector<int> &s){
    	std::sort(s.begin(),s.end());
		bool *flags = new bool[s.size()];
		for(int i=0;i<=s.size();i++){
			for(int j=0;j<i;j++) flags[j]=true;
			for(int j=i;j<s.size();j++) flags[j]=false;
			comb(s,s.size(),flags);
		}
		print();
		return result;
    }
};

int main(int argc, char *argv[]){
	ifstream fi(argv[1],ios::in);
	Solution sol;
	vector<int> s;
	int elem;
	for(int i=0;i<stoi(argv[2]);i++){
		fi >> elem;
		s.push_back(elem);
	}
	vector<int>::iterator it = s.begin();
	for(;it!=s.end();it++){
		cout << (*it) << endl;
	}
	vector<vector<int>> subset = sol.subsets(s);
	return 0;
}
