#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#define max 50
int main()
{       int b[10],n,x,i; 
	int sockfd,newsockfd,k;
	socklen_t actuallen;
	int retval;
	size_t leng;
	char c;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	char buff[max],temp[max];
	int a=0;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\n Socket creation error");
		exit(0);
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3391);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3392);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("\n Binding error");
		close(sockfd);
	 	exit(0);
	}
	actuallen=sizeof(clientaddr);
	
	
	
	
	
		retval=recvfrom(sockfd,b,sizeof(b),0,(struct sockaddr *)&clientaddr,&actuallen);
		retval=recvfrom(sockfd,&n,sizeof(n),0,(struct sockaddr *)&clientaddr,&actuallen);
		retval=recvfrom(sockfd,&x,sizeof(x),0,(struct sockaddr *)&clientaddr,&actuallen);		
		if(retval==-1)
		{
			close(sockfd);
			exit(0);
		}
		for(i=0;i<n;i++)
		{
		if(b[i]==x)
		  {
		  break;
		  }
		}
	retval=sendto(sockfd,&i,sizeof(i),0,(struct sockaddr *)&clientaddr,actuallen);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}

	close(sockfd);
}


