#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> comb;
public:
    void addSer(int n,bool *flags){
        vector<int> ser;
        for(int i=0;i<n;i++){
            if(flags[i]==true){
                ser.push_back(i+1);
            }
        }
        comb.push_back(ser);
    }
    
    vector<vector<int>> combine(int n,int r){
        int i,j,k;
        bool *flags = new bool[n];
        for(i=0;i<r;i++) flags[i]=true;
        for(i=r;i<n;i++) flags[i]=false;
    	addSer(n,flags);
    	for(i=n-1;i>0;i--){
    		if(flags[i]==false && flags[i-1]==true){
    			std::swap(flags[i],flags[i-1]);
    			for(j=i+1,k=i+1;j<n;j++){
    				if(flags[j]==true){
    					std::swap(flags[j],flags[k]);
    					++k;
    				}
    			}
    			addSer(n,flags);
    			i=n;
    		}
    	}
		return comb;
    }
    
	void print(){
		vector<vector<int>>::const_iterator it = comb.begin();
		for(;it!=comb.end();it++){
			for(int i=0;i<(*it).size();i++){
				cout << (*it)[i] << "\x20";
			}
			cout << endl;
		}	
	}
};

int main(int argc, char* argv[]){
	Solution sol;
	sol.combine(stoi(argv[1]),stoi(argv[2]));
	sol.print();
	return 0;
}
