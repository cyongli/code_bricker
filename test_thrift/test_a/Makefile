
DIR_SRC := gen-cpp
GEN_SRC := $(wildcard ${DIR_SRC}/*.cpp)
GEN_OBJ := $(patsubst %.cpp,%.o,$(notdir $(GEN_SRC)))

THRIFT_DIR := /usr/local/include/thrift
INC := -I$(THRIFT_DIR)
LINK_DIR := /usr/local/lib
LINK := -L/$(LINK_DIR)

.PHONY: all clean

all: server client

%.o: ${DIR_SRC}/%.cpp
	g++ -c $< -o $@
%.o: %.cpp
	g++ -c $< -o $@
server: CppServer.o $(GEN_OBJ)
	g++ $^ -o $@ -lthrift
client: CppClient.o $(GEN_OBJ)
	g++ $^ -o $@ -lthrift

clean:
	rm -rf *.o server client
