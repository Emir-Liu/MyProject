#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
/*
服务器
ip:所有
port:1234
*/

#define MAXN 4096

//./main.out para_1
//返回值：
//argc = 2
//argv[0] 指向程序路径及名称
//argv[1] 指向para_1字符串
int main(int argc ,char **argv)
{
	struct sockaddr_in A ,B ;
	//socket的内容为socket套接字地址(sockaddr_in)，
	//struct sockaddr_in{
    //unsigned short         sin_family;    //地址类型：AF——INET(TCP/IP传输协议)
    //unsigned short int     sin_port;     //端口号0-65535
    //struct in_addr         sin_addr;     //32位ip地址
    //unsigned char          sin_zero[8];  //填充字节，一般为0
    //};

    //meg存储发送的数据，rev存储接受的数据
	char meg[MAXN] ;
	char rev[MAXN] ;
	socklen_t len;
	//分别存储socket的操作码
	int s_socket,socket_conn;
	s_socket = socket(AF_INET,SOCK_STREAM,0);
	//int socket(int domain,int type,int protocol)
	//int domain: AF_UNIX（本机通信），AF_INET（TCP/IP-IPv4）,AF_INET6（TCP/IP-IPv6）
	//int type: SOCK_STREAM(TCP),SOCK_DGRAM(UDP),SOCK_RAW
	//int protocol =0确定套接字需要的协议簇和类型
	//返回值：成功返回套接字，失败返回-1，错误代码写入“errno”

	//检测是否成功创建套接字
	if(s_socket < 0)
	{
		printf("Faile to socket!\n");
		return 1;
	}

	//填写套接字地址
	A.sin_family = AF_INET ;
	//如果在调用程序前输入端口号则使用，如果没有则使用默认端口号1234
	if(argv[1])
	{
        //htons:将整形变量从主机字节顺序转变为网络字节顺序：高位字节放在内存的低地址
        //atoi:ascii to integer
		A.sin_port = htons(atoi(argv[1])) ;
	}
    else
        A.sin_port = htons(1234);
    //注意ip地址的填充方式
    //my_addr.sin_addr.s_addr = inet_addr("192.168.0.1");
	//htonl：将主机数转换为无符号长整型网络字节顺序
	//inaddr_any:inet_addr("0.0.0.0")
	//代表本机的所有IP，因为多网卡情况下，就代表所有网卡ip
	//需要明确的是当服务器的监听地址是INADDR_ANY时
	//设置的是服务器的IP地址
	//含义是让服务器端计算机上的所有网卡的IP地址都可以作为服务器IP地址
	//即监听外部客户端程序发送到服务器端所有网卡的网络请求。
	//使得服务器程序可以运行在任意计算机上，便于程序的移植
	A.sin_addr.s_addr = htonl(INADDR_ANY) ;
	//int bind(int sockfd,struct sockaddr * my_addr,int addrlen);
	//bind设置参数sockfd的socket名称，由sockfd指向sockaddr结构
	//对于不同的si_family有不同的结构
	//将操作码和内容连接
	bind(s_socket ,(struct sockaddr *)&A,sizeof(A));
	//等待连接
	//int listen(int s,int backlog);
	//将socket切换为listern模式，还没有开始接收连线
	//backlog 同时能够处理的最大连接要求
	listen(s_socket,5);
	printf("Server is Waiting ...\n");
	len = sizeof(struct sockaddr_in) ;

	//int accept(int s,struct sockaddr * addr,int * addrlen);
	//s为socket操作返回，经过bind,listen处理，当有连线时，返回新的socket处理代码
	//之后的数据传送与读取都由新的socket处理
	//原来的socket用accept接受新的连线请求
	//连线成功后，addr的指针会有远程主机的地址数据
	//成功返回处理码，失败返回-1
	socket_conn = accept(s_socket,(struct sockaddr *)&B ,&len);
	if(socket_conn >= 0)
	{
			printf("连接成功，开始通信！\n");
			while(1)
			{
                //meg用于存储数据
				fgets(meg,MAXN,stdin);
				//char * inet_ntoa(struct in_addr in);
				//将网络二进制的数字转换成网络地址
				//inet_ntoa(B.sin_addr);
				len = strlen(meg);
				if(meg[len-1] == '\n')
                    meg[len-1] = 0 ;
                //int send(int s,const void * msg,int len,unsigned int falgs);
				send(socket_conn,meg,strlen(meg)+1,0);
				printf("已经成功发送%d个字节\n",len);
				if(strcmp(meg,"quit") == 0)
				{
					printf("Server is cancelling the communication!\n");
					break ;
				}
				recv(socket_conn,rev,MAXN,0);
				if(strcmp(rev,"quit")==0)
				{
					printf("Client is cancelling the communication!\n");
					break ;
				}
				printf("成功接受%d个字符，字符为：%s\n",strlen(rev),rev);

			}
			close(socket_conn) ;
	}
	else
	{
		printf("Faile to aceept!\n");
	}
	close(s_socket);
	return 0;
}
