#include<iostream>
#include<algorithm>
using namespace std;

void recursive_perm(int list[],int s,int e){	
	if(s==e){
		for(int i=0;i<e;i++){
			cout << list[i] << "\x20";
		}
		cout << endl;
		return;
	}	
	for(int i=s;i<e;i++){
		std::swap(list[i],list[s]);
		recursive_perm(list,s+1,e);
		std::swap(list[i],list[s]);
	}
}

void perm(int list[],int n){
	std::sort(list,list+n);
	do{
		for(int i=0;i<n;i++){
			cout << list[i] << "\x20"; 
		}
		cout << endl;
	}
	while(std::next_permutation(list,list+n));
}

void perm_vector(vector<int> &num){
	std::sort(num.begin(),num.end());
	do{
		for(int i=0;i<num.size();i++){
			cout << num[i] << "\x20";
		}
		cout << endl;
	}while(std::next_permutation(num.begin(),num.end()));
}

int main(int argc, char* argv[]){
	int list[] = {1,1,3};
	vector<int> num;
	for(int i=0;i<3;i++){
		num.push_back(list[i]);
	}
	//recursive_perm(list,0,4);
	//perm(list,3);
	perm_vector(num);
	return 0;
}
