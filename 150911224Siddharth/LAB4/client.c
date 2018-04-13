#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#define max 200
using namespace std;
int main()
{
	int sockfd,retval,newsockfd,k=0;
	socklen_t actuallen;
	char temp[3];
	size_t leng;
	FILE *fp;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	char buff[max];
char buff1[max];
	char temp1[max];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\n Socket creation error");
		exit(0);
	}
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3381);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3380);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=bind(sockfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	if(retval==-1)
	{
		printf("\n Binding error");
		close(sockfd);
	 	exit(0);
	}

	cout<<"Enter option:\n1.Reg No. 2.Name 3.Subject Code:\n";
	int c[1];
	cin>>c[0];
	actuallen=sizeof(serveraddr);
	retval=sendto(sockfd,c,sizeof(c),0,(struct sockaddr *)&serveraddr,actuallen);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}
	cout<<"Enter value:"<<endl;
	string reg;
	cin>>reg;
	strcpy(buff, reg.c_str());

	actuallen=sizeof(serveraddr);
	retval=sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&serveraddr,actuallen);
	//puts(temp1);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}
	actuallen=sizeof(serveraddr);
	retval=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&serveraddr,&actuallen);
	puts(buff1);
	//printf("%c ",c);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}


	close(sockfd);
}

