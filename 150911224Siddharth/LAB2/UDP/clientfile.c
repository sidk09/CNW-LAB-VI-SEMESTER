#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
char buff[MAXSIZE][MAXSIZE];
 char filename[15];
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
int j;

printf("\nEnter File name: \n");
scanf("%s",filename);
strcpy(buff[0],filename);
printf("Enter Operation:\n1.Read\n2.Write\n3.Exit\n");
scanf("%d",&j);
switch(j)
{
	case 1: strcpy(buff[1],"1");
		break;
	case 2: strcpy(buff[1],"2");
		printf("Enter Text to be appended to file:\n");
		scanf("%s",buff[2]);
		break;
	case 3: exit(0);
}
sentbytes=send(sockfd,buff,sizeof(buff),0);
if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}
recedbytes=recv(sockfd,buff,sizeof(buff),0);
printf("\n%s\n",buff[0]);
close(sockfd);
}
