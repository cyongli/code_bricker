#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int len = gas.size();
		int result,i,j;
		for(i=0;i<len;i++){
			j=i;
			result = 0;
			do{
				if((result+=gas[j]-cost[j])<0){
					break;
				}
				j=(j+1)%len;
			}while(j!=i);
			if(result>=0) return i;
		}		        
		return -1;
   	}
};

int main(int argc, char *argv[]){

	return 0;
}
