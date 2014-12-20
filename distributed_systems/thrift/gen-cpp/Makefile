
DIR_SRC=gen-cpp
GEN_SRC := $(wildcard *.cpp)
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))
CXX = /opt/centos/devtoolset-1.1/root/usr/bin/g++ --std=c++11

all: build-in.o
build-in.o:${GEN_OBJ}
	ld -r -o $@ $^
%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
clean:
	rm -rf *.o
