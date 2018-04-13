#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

void main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;

//Data type to edit
int buff[MAXSIZE];

sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}
printf("%i",sockfd);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");

}
printf("enter the size of array\n");
int n,x;
scanf("%d",&n);
printf("enter the array\n");
for(x=0;x<n;x++)
	scanf("%d",&buff[x]);


//Send from Next Line
sentbytes=send(sockfd,&n,sizeof(n),0);

sentbytes=send(sockfd,buff,sizeof(buff),0);

if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}

//Receive from next line and print on the next line
recedbytes=recv(sockfd,buff,sizeof(buff),0);
int y;
for(y=0;y<n;y++)
	printf("%d ",buff[y]);
printf("\n");


close(sockfd);
}
