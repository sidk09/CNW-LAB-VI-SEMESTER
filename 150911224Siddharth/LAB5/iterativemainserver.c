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
	int sockfd, ret, csockfd; struct dns d[10];
	int rcvbytes,sentbytes;
	struct sockaddr_in serveraddr, mserveraddr, clientaddr;
	socklen_t len, lenm; char hname[50], ip[50];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
	}
	mserveraddr.sin_family=AF_INET;
	mserveraddr.sin_port=htons(3700);
	mserveraddr.sin_addr.s_addr=inet_addr("127.0.0.2");
	ret=bind(sockfd,(struct sockaddr*)&mserveraddr,sizeof(mserveraddr));
	len=sizeof(clientaddr);
	strcpy(d[0].hname, "www.yahoo.com");
	strcpy(d[0].ip, "122.133.45.67");
	strcpy(d[1].hname, "www.pizzaaa.com");
	strcpy(d[1].ip, "134.31.44.31");
	strcpy(d[2].hname, "www.dotcom.com");
	strcpy(d[2].ip, "111.222.32.22");
	while(1)
	{
		rcvbytes=recvfrom(sockfd,hname,sizeof(hname),0,(struct sockaddr*)&clientaddr, &len);
		if(rcvbytes==-1)
		{
			close(sockfd);
		}
	
		int flag = -1, i=0;
		for(i=0; i<3; i++)
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
		
			strcpy(ip, "Could not resolve.");
			sentbytes=sendto(sockfd,ip,sizeof(ip),0,(struct sockaddr*)&clientaddr, sizeof(clientaddr));
			if(sentbytes==-1)
			{
				close(sockfd);
			}
		
		}
	}
	close(sockfd);
}

	
