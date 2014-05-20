
HDFS_INCLUDE=${HADOOP_PREFIX}/src/c++/libhdfs
CPPFLAGS=-I${HDFS_INCLUDE} -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux
LIBHDFS= -L/home/chaoyli/hadoop/c++/Linux-i386-32/lib 
LIBJAVA= -L${JAVA_HOME}/jre/lib/i386/server
CC= gcc --std=c11
testhdfs:testhdfs.c
	$(CC) -Wall $< $(CPPFLAGS) $(LIBHDFS) -lhdfs $(LIBJAVA) -ljvm -o $@

.PHONY: clean
clean:
	rm -rf testhdfs
