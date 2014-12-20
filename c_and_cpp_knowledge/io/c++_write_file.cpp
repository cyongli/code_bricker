#include<fstream>
#include<string>
using std::string;
using std::ofstream;
using std::ios;
using std::endl;

int main(){
	ofstream table("table.tbl", ios::out);
	string username = "hello";
	int age = 5;;
	table << username << "\x20";
	table << age << endl;
	table.close();
	return 0;
}
