#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<typeinfo>
using namespace std;

int main(){
	ifstream table("table.tbl",ios::in|ios::out);
	string username;
	int age;
	string sage;
	cout<<left;
	while(table.good()){
		table>>username;
		table>>age;
		cout<<setw(10)<<username<<"\x20";
		cout<<setw(10)<<age<<endl;
	}
	//cout<<b<<endl;
	table.close();
	return 0;
}
