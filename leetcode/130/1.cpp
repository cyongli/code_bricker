#include<iostream>
#include<ctime>
using namespace std;

static bool prior(int r1,int r2){
    return r1<r2;
}

int main(int argc, char *argv[]){
    cout << (prior(3,2)==true) << endl;
    return 0;
}
