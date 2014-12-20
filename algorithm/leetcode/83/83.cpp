/*
 题意:求一个数的sqrt
	  用牛顿插值法 f(x)=x^2-S=0;
	  x(n+1) = x(n)-f(n)/f'(x(n)) = (x(n)+S/(x(n))/2;
	  初值选择:S=a*10^(2n),如果a>=10,初值为6*10(n);a<10,初值为2*10(n)
*/

#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        int num = x;
        int i = 0;
        while(num/100){
            num = num/100;
            ++i;
        }
        double start;
        if(num>=10){
            start = 6*(10<<i);
        }
        else start = 2*(10<<i);
		start /= 10;
		cout << start << endl;
        double precision = 1e-6;
        while(abs(start*start-x)>precision){
            start = (start+x/start)/2;
        }
		cout << start << endl;
        return (int)start;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	cout << sol.sqrt(stoi(argv[1])) << endl;
	return 0;
}
