#include<iostream>
#include<string>
using namespace std;

void reverse(string& s, int start, int end){
    int i = start;
    int j = end;
    for(; i<=j; i++,j--){
	char c = s[i];
	s[i]=s[j];
	s[j]=c;
    }
}

void reverseWords(string &s){
    int i,j=0;
    for(i=0; i<s.length() & s[i] == '\x20'; i++);
    s.erase(0,i);
    for(j=s.length()-1; j>=0 & s[j] == '\x20'; j--);
    s.erase(j+1,s.length()-j-1);

    reverse(s, 0, s.length()-1);
    
    int start = 0;
    int end = 0;
    while( (end=s.find('\x20',start)) != string::npos){
	for(i=end+1; s[i] == '\x20'; i++);
	s.erase(end+1, i-end-1);   
	reverse(s, start, end-1);
	start = end+1;
    }

    reverse(s, start, s.length()-1);
}

int main(int argc, char* argv[]){
    string s(argv[1]);
    reverseWords(s);
    return 0;
}			     
