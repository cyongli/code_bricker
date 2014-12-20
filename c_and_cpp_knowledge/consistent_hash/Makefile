CXX = /opt/centos/devtoolset-1.1/root/usr/bin/g++ --std=c++11
all: consistent

consistent : consistent.h hashring_example.cpp
	$(CXX) -Wno-deprecated hashring.cpp -o consistent -lcrypto

.PHONY : clean

clean :
	rm consistent
