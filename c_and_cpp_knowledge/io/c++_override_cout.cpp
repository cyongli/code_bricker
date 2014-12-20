#include <iostream>
#include <fstream>
using namespace std;

class test{
public:
	test(const string& data):data(data){};
	friend ofstream& operator << (ofstream& out, const test& t){
		out << t.data;
		return out;
	}
	friend ostream& operator << (ostream& out, const test& t){
		out << t.data;
		return out;
	}
private:
	string data;

};

int main(int argc, char* argv[]){
	test t("hello");
	ofstream table("table.tbl", ios::out);
	table << t << endl;
	table.close();
	cout << t << endl;
	return 0;
}
