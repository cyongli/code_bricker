#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

#include <iostream>
#include <string>
using namespace std;
#include "Row.h"

char* deserializeInt(char* buffer, int* value){
	(*value) = *value | (buffer[3] & 0xff);	
	(*value) = *value | (buffer[2] & 0xff) << 8 ;
	(*value) = *value | (buffer[1] & 0xff) << 16;
	(*value) = *value | (buffer[0] & 0xff) << 24;
	return buffer+4;
}

char* deserializeString(char* buffer, string* value, int len){
	for(int i=0;i<len;i++){
		value->push_back(buffer[i]);
	}
	return buffer+len;
}

void deserializeRow(char* buffer, struct Row* value){
	int len = 0;
	buffer = deserializeInt(buffer, &len);
	buffer = deserializeString(buffer, &(value->key), len);
	len = 0;
	buffer = deserializeInt(buffer, &len);
	buffer = deserializeString(buffer, &(value->value), len);
}

int rcvMessage(){
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);//Create socket

	//Prepare the sockaddr_in structure;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(9512);
	
	//Bind to address and port
	while (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0){
		cout << "bind error:" << strerror(errno) << endl;
		sleep(20);
	}
	cout << "bind done" << endl;

	listen(socket_desc, 3);//Listen the socket

	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	char buffer[100]={'\0'};
	while (new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c)){
		//accept返回一个新的socket
		if(new_socket < 0){
			perror("accept failed");
			break;
		}
		puts("Connection accepted");
		if(recv(new_socket, buffer, 100, 0)<0){
			puts("Recv request failed");
			break;
		}
		struct Row row;
		deserializeRow(buffer, &row);		
		cout << row.key << " and size is "<< row.key.size() << endl;
		cout << row.value << " and size is " << row.value.size() << endl;
		//memset(buffer,0,sizeof buffer);
	}
	close(socket_desc);//close socket
	return 0;
}

int main(int argc, char* argv[]){
	rcvMessage();	
	return 0;
}

