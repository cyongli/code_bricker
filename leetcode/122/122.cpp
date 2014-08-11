#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		int len = num.size();
    	int i,j=0,k=0;
		for(i=len-1;i>0 && num[i]<=num[i-1];i--);
		j = i-1;
		if(j<0) {
			std::reverse(num.begin(),num.end());
			vector<int>::iterator it = num.begin();
			for(;it!=num.end();it++){
				cout << *(it) << "\x20";
			}
			cout << endl;
			return;
		}
		for(i=len-1;i>=0 && num[i]<=num[j];i--);
		k = i;
		std::swap(num[j],num[k]);
		for(i=0;i<(len-j-1)/2;i++){
			std::swap(num[j+1+i],num[len-1-i]);
		}
		vector<int>::iterator it = num.begin();
		for(;it!=num.end();it++){
			cout << *(it) << "\x20";
		}
		cout << endl;
    }
};

int main(int argc, char* argv[]){
	ifstream fi(argv[1],ios::in);
	vector<int> num;
	int elem;
	for(int i=0;i<stoi(argv[2]);i++){
		fi >> elem;
		num.push_back(elem);
	}
	vector<int>::iterator it = num.begin();
	for(;it!=num.end();it++){
		cout << *(it) << "\x20";
	}
	cout << endl << "after next" << endl;
	Solution sol;
	sol.nextPermutation(num);
	return 0;
}
