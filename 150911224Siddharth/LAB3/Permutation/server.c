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

void permute(char*, int, int);

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
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3791);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3792);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("\n Binding error");
		close(sockfd);
	 	exit(0);
	}
	actuallen=sizeof(clientaddr);

	while(1)
	{
		char str[10];

		retval=recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr *)&clientaddr,&actuallen);

		if (strcmp(str,"exit0")==0)
			break;

		permute(str, 0, strlen(str)-1);

		strcpy(str,"Done");
		retval=sendto(sockfd,str,sizeof(str),0,(struct sockaddr *)&clientaddr,actuallen);

	}

	return 0;
}

void permute(char str[], int l, int r)
{
	int i;
	if (l==r)
		printf("%s\n", str);
	else
	{
		for (i=l; i<=r; i++)
		{
			char t=str[l];
			str[l]=str[i];
			str[i]=t;

			permute(str, l+1, r);

			t=str[l];
			str[l]=str[i];
			str[i]=t;
       }
   }
}
