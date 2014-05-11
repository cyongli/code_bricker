
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
	g++ $(INC) -c $< -o $@
%.o: %.cpp
	g++ $(INC) -c $< -o $@
server: server.o $(GEN_OBJ)
	g++ $(LINK) $^ -o $@ -lthrift
client: client.o $(GEN_OBJ)
	g++ $(LINK) $^ -o $@ -lthrift

clean:
	rm -rf *.o server client
