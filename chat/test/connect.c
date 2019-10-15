#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr

int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if(socket_desc == -1  )
	{
		printf("create socket error\n");
		exit(0);
	}
	else
	{
		printf("create socket\n");
	}
		
	server.sin_addr.s_addr = inet_addr("14.215.177.39");
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

	//Connect to remote server
	
	if(connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("connect error\n");
		exit(0);
	}
	else
	{
		printf("connected\n");
	}
	return 0;
}
