#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>

bool quit = false;

void handler(int signal){
	quit = true;
}

int main(int argc, char* argv[]){
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1){
		printf("Could not create socket");
	}

	//Prepare the sockaddr_in structure;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(9512);
	
	//Bind to address and port
	if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0){
		puts("bind failed");
		return 1;
	}
	puts("bind done");


	//signal(SIGINT, handler);
	//Listen the socket
	listen(socket_desc, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	char from[1000];
	//int from;
	while (new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c)){
		//accept返回一个新的socket
		if(new_socket < 0){
			perror("accept failed");
			//break;
			return 0;
		}
		puts("Connection accepted");
		if(recv(new_socket, from, sizeof from, 0)<0){
			puts("Recv request failed");
			//continue;
			return 0;
		}
		else 
			printf("request message:%s\n",from);
		
		//Reply to the client
		const char* message = "Hello Client,I have received your connection";
		write(new_socket, message, strlen(message)+1);
	}

	close(socket_desc);//close socket
	
	return 0;
}
