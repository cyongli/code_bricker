#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main(int argc, char* argv[]){
	
	void* context = zmq_ctx_new();
	void* responder = zmq_socket(context, ZMQ_REP);
	int rc = zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);

	for(int i=0;i<20;i++){
		char buffer[10];
		zmq_recv(responder, buffer, 10, 0);
		printf("received:%s\n",buffer);
		//sleep(1);
		//zmq_send(responder, "server", 6, 0);
	}
	printf("well done\n");
	return 0;
}
