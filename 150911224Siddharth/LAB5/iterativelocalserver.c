#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
struct dns{
	char hname[50];
	char ip[50];
};
int main()
{
	int sockfd, ret, csockfd;
	int rcvbytes,sentbytes; struct dns d[10];
	struct sockaddr_in serveraddr, mserveraddr, clientaddr;
	socklen_t len, lenm; char hname[50], ip[50];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3702);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	ret=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(ret==1)
	{
		printf("Binding error");
		close(sockfd);
	}
	
	len=sizeof(clientaddr);
	strcpy(d[0].hname, "www.google.com");
	strcpy(d[0].ip, "123.45.67.89");
	strcpy(d[1].hname, "www.amazon.in");
	strcpy(d[1].ip, "239.98.97.96");
	while(1)
	{
		rcvbytes=recvfrom(sockfd,hname,sizeof(hname),0,(struct sockaddr*)&clientaddr, &len);
		if(rcvbytes==-1)
		{
			close(sockfd);
		}
	
		int flag = -1, i=0;
		for(i=0; i<2; i++)
		{
			if(strcmp(hname, d[i].hname)==0)
			{
				flag = i;
				break;
			}
		}
	
		if(flag>=0)
		{
			
		
			strcpy(ip, d[flag].ip);
			sentbytes=sendto(sockfd,ip,sizeof(ip),0,(struct sockaddr*)&clientaddr, sizeof(clientaddr));

			if(sentbytes==-1)
			{
				close(sockfd);
			}
		}
		else if(strcmp(hname, "stop")==0)
		{
			close(sockfd);
			break;
		}
		else
		{
			strcpy(ip, "Error.");
			sentbytes=sendto(sockfd,ip,sizeof(ip),0,(struct sockaddr*)&clientaddr, sizeof(clientaddr));
			if(sentbytes==-1)
			{
				close(sockfd);
			}
		
		}
	}
	close(sockfd);
}

	
