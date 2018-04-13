#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
	int sockfd, newsockfd, retval;
	socklen_t actlen;
	int rcvbytes, sentbytes;
	struct sockaddr_in serveraddr, clientaddr;
	char buffer[100], find[100], rep[100]; 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
		printf("\nSocket Error.");
	
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
	retval = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	if(retval == -1)
	{
		printf("\nBind Error.");
		close(sockfd);
	}
	retval = listen(sockfd, 1);
	if(retval == -1)
	{
		close(sockfd);
	}
	actlen = sizeof(clientaddr);
	newsockfd = accept(sockfd, (struct sockaddr*)&clientaddr,&actlen);
	if(newsockfd == -1)
	{
		close(sockfd);
	}
	int n, rn;
	rcvbytes = recv(newsockfd, &rn, sizeof(rn), 0);
	n = ntohl(rn);
	if(rcvbytes == -1)
	{
		close(sockfd);
		close(newsockfd);
	}
	int arr[50], ritem, item, flag=0,i;
    	rcvbytes = recv(newsockfd, arr, sizeof(arr), 0);
	if(rcvbytes == -1)
	{
		close(sockfd);
		close(newsockfd);
	}
    	rcvbytes = recv(newsockfd, &ritem, sizeof(ritem), 0);
	if(rcvbytes == -1)
	{
		close(sockfd);
		close(newsockfd);
	}
	item = ntohl(ritem);
	for(i=0;i<n;i++)
	{
		if(arr[i] == item)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
		sentbytes = send(newsockfd, "Element found!", sizeof("Element found!"),0);
	else
		sentbytes = send(newsockfd, "Element not found!", sizeof("Element not found!"),0);			
		
	if(sentbytes == -1)
		{
			close(sockfd);
			close(newsockfd);
		}	
	
	close(sockfd);
	close(newsockfd);
}
