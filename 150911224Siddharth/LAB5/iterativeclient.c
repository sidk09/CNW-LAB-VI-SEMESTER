#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int sockfd, ret, csockfd;
	int rcvbytes,sentbytes;
	struct sockaddr_in serveraddr, clientaddr, mserveraddr;
	socklen_t len; char hname[50], ip[50];
	char buff[100];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3702);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	mserveraddr.sin_family=AF_INET;
	mserveraddr.sin_port=htons(3700);
	mserveraddr.sin_addr.s_addr=inet_addr("127.0.0.2");
	printf("Enter the host name. ");
	scanf("%s", hname);
	do
	{
		sentbytes=sendto(sockfd,hname,sizeof(hname),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

		if(sentbytes==-1)
		{
			close(sockfd);
		}
		len = sizeof(serveraddr);
		rcvbytes=recvfrom(sockfd,ip,sizeof(ip),0,(struct sockaddr*)&serveraddr,&len);
		if(strcmp(ip, "Error.")==0)
		{
			sentbytes=sendto(sockfd,hname,sizeof(hname),0,(struct sockaddr*)&mserveraddr,sizeof(mserveraddr));

			if(sentbytes==-1)
			{
				close(sockfd);
			}
			len = sizeof(mserveraddr);
			rcvbytes=recvfrom(sockfd,ip,sizeof(ip),0,(struct sockaddr*)&mserveraddr,&len);
			puts(ip);
		}
		else
			puts(ip);
		printf("\n");
		printf("Enter another host name or stop to stop. ");
		scanf("%s", hname);
		if(strcmp(hname, "stop")==0)
		{
			sentbytes=sendto(sockfd,"stop",sizeof("stop"),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
			sentbytes=sendto(sockfd,"stop",sizeof("stop"),0,(struct sockaddr*)&mserveraddr,sizeof(mserveraddr));
		}
	}while(strcmp(hname, "stop")!=0);
	close(sockfd);
}
