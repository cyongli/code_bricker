#include <iostream>
using namespace std;

class outer{
	public:
		outer()  {}
		~outer() {}
		void show();
		
		class inner{
			public:
				inner()  {}
				~inner() {}
				void _show();
		};
	private:
		inner* myInner;
};

void outer::show(){
	cout << "to show" << endl;
	myInner->_show();
}

	
void outer::inner::_show(){
	cout << "show inner" << endl;
	cout << a << endl;
}

int main(int argc, char* argv[]){
	outer* my_outer = new outer();
	my_outer->show();
	return 0;
}

