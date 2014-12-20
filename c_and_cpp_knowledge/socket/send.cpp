#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <iostream>

int initConnection(){
	
	int socket_desc;
	struct sockaddr_in server;
	
	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1){
		printf("Could not create socket!");
	}

	//Prepare the sockaddr_in structure;
	server.sin_addr.s_addr = inet_addr("192.168.120.221");
	server.sin_family = AF_INET;
	server.sin_port = htons(9512);

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0){
		puts("connect error");
		return 1;
	}	
	puts("Connected");
	
	return socket_desc;
}

int sendMessage(int socket_desc){
	//Send a message
	const char* message = "Hello Socket";
	if (send(socket_desc, message, sizeof message, 0) < 0){
		puts("Send failed");
		return 1;
	}
	puts("Data Send");

	//Receive a replay from the server
	char server_reply[2000];
	if (recv(socket_desc, server_reply, 2000, 0) < 0){
		puts("recv failed");
	}
	printf("Reply received:%s\n",server_reply);
	close(socket_desc);
	return 0;

}

int main(int argc, char* argv[]){
	int socket_desc = initConnection();
	sendMessage(socket_desc);
	//std::cout << socket_desc << std::endl;
	//std::thread t(sendMessage, socket_desc);
	//t.join();
	//pause();
	return 0;
}
