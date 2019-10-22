#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *connect_server(void *);

int main(int argc , char *argv[])
{
  int socket_desc , new_socket , c,*new_sock;
  struct sockaddr_in server , client;
  char *message;

  //Create socket
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1)
  {
    printf("Could not create socket");
  }

  //Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 5555 );

  //Bind
  if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
  {
    puts("bind failed");
    return 1;
  }
  puts("bind done");

  //Listen
  listen(socket_desc , 3);

  //Accept and incoming connection
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);

  while(new_socket=accept(socket_desc,(struct sockaddr *)&client, (socklen_t*)&c))
  {
    puts("Connection accepted");

    //Reply to the client
    message = "Hello Client , I have received your connection.\n";
    write(new_socket , message , strlen(message));

    pthread_t sniffer_thread;
    new_sock = malloc(1);
    *new_sock = new_socket;

    if(pthread_create(&sniffer_thread,NULL,connect_server,(void*)new_sock) > 0)
    {
      printf("could not create thread");
      return 1;
    }
    puts("handler assignment");
    if(new_socket < 0)
    {
      printf("accept failed");
      return 1;
    }
  }	
  return 0;
}

void *connect_server(void *socket_desc)
{
	int sock = *(int *)socket_desc;
	int read_size;
	char *message,client_message[2000];
	message = "Greetings!I am your connection handler\n";
	write(sock,message,strlen(message));

	message = "It is my duty to communicate with you\n";
	write(sock,message,strlen(message));
	
	while( (read_size = recv(sock,client_message,2000,0) ) > 0 )
	{
		if( strcmp(client_message,"exit") == 0)
		{
			fflush(stdout);
			break;
			
		}
		write(sock,client_message,strlen(client_message));
	}

	if(read_size == 0)
	{
		puts("client disconnect");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		puts("recv failed");
	}

	return 0;
}
