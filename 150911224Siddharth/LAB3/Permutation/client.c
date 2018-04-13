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

int main()
{
    int sockfd,retval;
	socklen_t actuallen;
	struct sockaddr_in serveraddr,clientaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\n Socket creation error");
		exit(0);
	}
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3792);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3791);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=bind(sockfd,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
	if(retval==-1)
	{
		printf("\n Binding error");
		close(sockfd);
	 	exit(0);
	}

	actuallen=sizeof(serveraddr);

	while(1)
	{
		printf("Enter a string: ");
		char str[10];
		scanf("%s",str);

		retval=sendto(sockfd,str,sizeof(str),0,(struct sockaddr *)&serveraddr,actuallen);

		if (strcmp(str,"exit0")==0)
			break;

		retval=recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr *)&serveraddr,&actuallen);

	}

	return 0;
}
