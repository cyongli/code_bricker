#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

void helloWorld(){
    ofstream savefile("/home/chaoyli/helloWorld.txt");
    savefile << "Third concurrent thread!" << endl;
    savefile.close();
}

void hello(){
    ofstream savefile("/home/chaoyli/hello.txt");
    savefile << "Hello Concurrent world!" << endl;
    savefile.close();
	thread t(helloWorld);
	t.detach();
}

int main(int argc, char *argv[]){
    thread t(hello);
    t.detach();
	pthread_exit(NULL);
    //this_thread::sleep_for(chrono::seconds(10));
}
