#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
/*
客户端
ip:本机
port:1235
*/
#define MAXN 4096

int main(int argc, char **argv)
{
	int c_socket ,conn;
	int len ;
	char rev[MAXN] ,buf[MAXN];
	struct sockaddr_in A ;
//配置客户端的socket
	c_socket = socket(AF_INET,SOCK_STREAM,0);
	A.sin_family = AF_INET ;
	if(argv[1])
	{
		A.sin_port = htons(atoi(argv[1]));
	}
  else
  {
        A.sin_port = htons(1235);
  }
	if(argv[2])
	{
		A.sin_addr.s_addr = inet_addr(argv[2]);
	}
	else
	{
        A.sin_addr.s_addr = htonl(INADDR_ANY) ;
	}
	
//int connect(int sockfd,const struct sockaddr* server_addr,socklen_t addrlen)
//返回:0 成功 -1 失败
//sockfd 指定数据发送的套接字，客户端的套接字
//server_addr 指定数据发送的目的地，也就是服务器的地址
	
	conn = connect(c_socket,(struct sockaddr *)&A,sizeof(struct sockaddr_in));
	if(conn >= 0)
	{
		printf("正在进行通信！\n");
		while(1)
		{
			recv(c_socket,rev,MAXN,0);
			if(strcmp(rev,"quit") == 0)
			{
				printf("Server is Cancelling the communication!\n");
				break ;
			}
            printf("成功接收到了%d字符，字符为：%s\n",strlen(rev),rev);
			fgets(buf,MAXN,stdin);
			len = strlen(buf) ;
			if(buf[len-1] == '\n')	buf[len-1] = 0 ;
			send(c_socket,buf,strlen(buf)+1,0);
			if(strcmp(buf,"quit") == 0)
			{
				printf("Client is Cancelling the communication!\n");
				break ;
			}
		}
		printf("Communication is Done!\n");
	}
	else{
		printf("Faile to connet\n");
		return 1;
	}
	close(c_socket);
	return 0;
}
