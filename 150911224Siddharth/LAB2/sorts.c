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



void bsort(int a[],int n)
{	
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
					{
						int temp=a[j];
						a[j]=a[j+1];
						a[j+1]=temp;
					}	
			}
}








int main()
{
	int sockfd,newsockfd,k;
	socklen_t actuallen;
	int retval;
	size_t leng;
	char c;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	int buff[max],temp[max];
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
	
	
	int n=0;
	retval=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&clientaddr,&actuallen);
	retval=recvfrom(sockfd,&n,sizeof(n),0,(struct sockaddr *)&clientaddr,&actuallen);
	
	
	
	bsort(buff,n);

	sentbytes=send(newsockfd,buff,sizeof(buff),0);
	
	
	
	
	
	
	
	retval=sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&clientaddr,actuallen);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}

	close(sockfd);
	
	
	
	
}

