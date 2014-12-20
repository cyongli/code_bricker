#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings){
		int *candyNum = new int[ratings.size()];
		for(int i=0;i<ratings.size();i++){
			candyNum[i]=1;
		}
		for(int i=1;i<ratings.size();i++){
			if(ratings[i] > ratings[i-1]){
				candyNum[i] = candyNum[i-1] + 1;
			}
		}
		for(int i=ratings.size()-2;i>=0;i--){
			if(ratings[i]>ratings[i+1] && candyNum[i] <= candyNum[i+1]){
				candyNum[i] = candyNum[i+1]+1;
			}
		}
		int result = 0;
		for(int i=0;i<ratings.size();i++){
			result += candyNum[i];
		}
		delete [] candyNum;
		return result;
	}	
};

int main(int argc, char *argv[]){
	ifstream fi(argv[1],ios::in);
	vector<int> ratings;
	int rate;
	for(int i=0;i<stoi(argv[2]);i++){
		fi >> rate;
		ratings.push_back(rate);
	}
	vector<int>::const_iterator it = ratings.begin();
	for(;it!=ratings.end();it++){
		cout << *(it) << "\x20";
	}
	cout << endl;
	Solution sol;
	cout << "min:" << sol.candy(ratings) <<endl;
	return 0;
}
