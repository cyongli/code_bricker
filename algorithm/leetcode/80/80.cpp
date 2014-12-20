#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int min(int a, int b, int c){
        return std::min(std::min(a,b),c);
    }

    int minDistance(string word1, string word2) {
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        int l1 = word1.size();
        int l2 = word2.size();
        int **d = new int*[l1+1];
        int i,j;
        for(i=0;i<=l1;++i) d[i] = new int[l2+1];
        for(i=0;i<=l1;++i) d[i][0] = i;
        for(i=0;i<=l2;++i) d[0][i] = i;
        for(i=0;i<l1;++i){
            for(j=0;j<l2;++j){
                int tmp = 1;
                if(word1[i]==word2[j]){
                    tmp = 0;
                }
                d[i+1][j+1] = min(d[i+1][j]+1,d[i][j+1]+1,d[i][j]+tmp);
            }
        }
		for(i=0;i<=l1;++i){
			for(j=0;j<=l2;++j){
				cout << d[i][j] << "\x20";
			}
			cout << endl;
		}
        return d[l1][l2];
    }
};

int main(int argc, char *argv[]){
	string word1(argv[1]);
	string word2(argv[2]);
	Solution sol;
	cout << sol.minDistance(word1,word2) << endl;
	return 0;
}
