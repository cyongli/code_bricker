#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

stack<int> oper;

int cal(int left,int right,char operand){
    int res = 0;
    switch(operand){
    case '+': res = left+right; break;
    case '-': res = left-right; break;
    case '*': res = left*right; break;
    case '/': res = left/right; break;
    default: break;
    }
    return res; 
}

int evalRPN(vector<string>& tokens){
    vector<string>::const_iterator it = tokens.begin();
    int eval = stoi(*it++);
    oper.push(eval);
    int left,right;
    for(; it!=tokens.end(); it++){
	if( (*it) == "+" | (*it) == "-" | (*it) == "*" | (*it) == "/"){
	    right = oper.top();
	    oper.pop();
	    left = oper.top();
	    oper.pop();
	    eval = cal(left,right,(*it)[0]);
	    oper.push(eval);
	}
	else{
	    oper.push(stoi(*it));
	}
    }
    return eval;
}

int main(int argc, char* argv[]){
    vector<string> tokens;
    for(int i=1;i<argc;i++){
	tokens.push_back(argv[i]);
    }
    cout << evalRPN(tokens) << endl;
    return 0;
}
