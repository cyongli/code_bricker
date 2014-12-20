#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
		if(ratings.size()==0) return 0;

		int	min = 0;
		int len = ratings.size();
		int froVally=0,postVally=0,peak=0;
		int *a = new int[ratings.size()];
		int i;

		for(i=0;i<len-1 && (ratings[i]>=ratings[i+1]);i++);
		postVally = i;
		a[postVally]=1;
		min+=a[postVally];
		for(i=postVally-1;i>=froVally;i--){
			if(ratings[i]==ratings[i+1]){
				a[i]=a[i+1];
				min += a[i];
			}
			else if(ratings[i]>ratings[i+1]){
				a[i]=a[i+1]+1;
				min += a[i];
			}
		}	
		if(postVally==len-1) goto L;
	
		while(postVally<len-1){	
			froVally = postVally;
			/*相同的ratings可以不相等*/
			for(i=froVally;i<len-1 && (ratings[i]<=ratings[i+1]);i++);
			peak = i;
			for(i=peak;i<len-1 && (ratings[i]>=ratings[i+1]);i++);
			postVally = i;		

			for(i=froVally+1;i<peak;i++){
				if(ratings[i]>ratings[i-1]){
					a[i]=a[i-1]+1;
					min += a[i];
				}
				else{
						a[i]=a[i-1];
						min += a[i];
				}
			}
			if(peak==len-1) {
				a[peak]= (ratings[peak-1]==ratings[peak]?(a[peak-1]):(a[peak-1]+1));
				min += a[peak]; 
				goto L;
			};

			a[postVally]=1;
			min+=a[postVally];
			for(i=postVally-1;i>peak;i--){
					if(ratings[i]>ratings[i+1]){
							a[i]=a[i+1]+1;
							min += a[i];
					}
					else{
							a[i]=a[i+1];
							min += a[i];
					}
			}
			if(a[peak-1]>a[peak+1]){
				a[peak] = (ratings[peak-1]==ratings[peak]) ? (a[peak-1]) : (a[peak-1]+1);
			}
			else if(a[peak-1]<a[peak+1]){
				a[peak]= (ratings[peak+1]==ratings[peak]) ? (a[peak+1]) : (a[peak+1]+1);

			}
			else{
				a[peak] = (ratings[peak+1]>ratings[peak-1]) ? (a[peak+1]+1) : (a[peak-1]+1);
			}
			min += a[peak];
		}

		L:
			cout << min << endl;
			froVally=0;
			postVally=0;
			peak=0;
			for(i=0;i<len-1;i++){
				if(ratings[i]==ratings[i+1]){
					froVally = i;
					for(;i<len && (ratings[i]==ratings[froVally]);i++);
					postVally=i;
					for(i=froVally+1;i<postVally-1;i++){
						if(a[i]!=1){
							min -= 1;
						}
					}
					
					if((postVally==len || ratings[postVally-1]>ratings[postVally]) && a[postVally-1]>1) {
						min-=1;
					}
					else if(froVally==0 && a[froVally]>1){
						min-=1;
					}
					i=postVally;
				}
			}
			return min;
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
