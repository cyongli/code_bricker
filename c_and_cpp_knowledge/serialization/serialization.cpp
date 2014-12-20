#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;

#include "Row.h"

char* serializeInt(char* buffer, int value){
  	/* Write big-endian int value into buffer; assumes 32-bit int and 8-bit char. */
  	buffer[0] = value >> 24;
 	buffer[1] = value >> 16;
  	buffer[2] = value >> 8;
  	buffer[3] = value;
  	return buffer + 4;
}

char* serializeString(char* buffer, const string& value){
  	for(int i=0;i<value.size();i++){
		buffer[i] = value[i];			
	}
  	return buffer+value.size();
}

void serializeRow(char* buffer, struct Row* row){
	/*只能对int型的非负数和char型进行序列化*/
  	buffer = serializeInt(buffer, (row->key).size());
	buffer = serializeString(buffer, row->key);
	buffer = serializeInt(buffer, (row->value).size());
	buffer = serializeString(buffer, row->value);
}

int sendMessage(char* buffer){
	
	int socket_desc;
	struct sockaddr_in server;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);//Create socket
	if(socket_desc == -1){
		cout << "create socket error" << endl;
		return 1;
	}
	
	//Prepare the sockaddr_in structure;
	server.sin_addr.s_addr = inet_addr("192.168.120.221");
	server.sin_family = AF_INET;
	server.sin_port = htons(9512);

	if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0){
		cout << "connect error" << endl;
		return 1;
	}

	if (send(socket_desc, buffer, 100, 0) < 0){
		puts("Send failed");
		return 1;
	}
	puts("Data Send");

	close(socket_desc);

	return 0;

}

int main(int argc, char* argv[]){
	struct Row row(argv[1],argv[2]);
	char buffer[100]={'\0'};
	serializeRow(buffer, &row);
	sendMessage(buffer);
	return 0;
}

