#include<iostream>
#include<vector>
using namespace std;

//string list="12345";

void recursive_comb(int* list,int n,int r,int subset[]){
	if(r==0){
		//cout << subset << endl;
		for(int i=0;i<3;i++){
			cout << subset[i] << "\x20";
		}
		cout << endl;
		return;
	}
	for(int i=n;i>=r;i--){
		subset[r-1]=list[i-1];
		recursive_comb(list,i-1,r-1,subset);
	}
}

void print(int *list,int n,bool *flags){
	for(int i=0;i<n;i++){
		if(flags[i]==true){
			cout << list[i] << "\x20";
		}
	}
	cout << endl;
}

void comb(int *list,int n,bool *flags){
	print(list,n,flags);
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
			print(list,n,flags);
			i=n;
		}
	}
}

int main(int argc, char *argv[]){
	int n = stoi(argv[1]);
	int r = stoi(argv[2]);
	int *pos = new int[n];
	for(int i=0;i<n;i++){
		pos[i]=i+1;
	}
	bool *flags = new bool[n];
	for(int i=0;i<r;i++) flags[i]=true;
	for(int i=r;i<n;i++) flags[i]=false;
	comb(pos,n,flags);
	//int subset[3];
	//recursive_comb(pos,5,3,subset);
	return 0;
}
