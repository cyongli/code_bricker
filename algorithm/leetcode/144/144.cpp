#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(const string &str){
        int len = str.size();
        if(0==len) return false;
        else if(1==len && (str[0]-'0'>9 || str[0]-'0'<0 )) return false;
        else{
            if( !(str[0]=='+' ||  str[0]=='-' || ((str[0]-'0'<=9) && (str[0]-'0'>=0))))return false;
            for(int i=1;i<len;++i){
                if(!(str[i]-'0'<= 9 && str[i]-'0'>=0) ) return false;
            }
        }
        return true;
    }

    int atoi(const char *str) {	
		int len = strlen(str);
		if(0==len) return 0;
		string numer;
		for(int i=0;i<len;i++){
			if(!(str[i]=='+' ||  str[i]=='-' || ((str[i]-'0'<=9) && (str[i]-'0'>=0)) || str[i]==' '))
				break;
			else if(str[i]!=' '){
				numer.push_back(str[i]);
			}
			else if(str[i]==' ' && i!=0 && str[i-1]!=' ')
				break;
		}
        if(!isValid(numer)) return 0;
		long long ret=0;
		int i=0;
		if(numer[0]=='+' || numer[0]=='-') 
			i = 1;
		for(;i<numer.size();++i){
			ret = ret*10 + numer[i]-'0';
		}
		#define INT_MAX 2147483648
		if(numer[0]=='-' && ret == INT_MAX) return -1*ret;
		else if(numer[0]=='-' && ret > INT_MAX) ret = INT_MAX;
		else if(ret>=INT_MAX) ret = INT_MAX-1;
		return ((numer[0]=='-') ? -1*ret : ret);
	}
};

int main(int argc, char *argv[]){
	Solution sol;
	cout << sol.atoi(argv[1]) << endl;	
	return 0;
}
