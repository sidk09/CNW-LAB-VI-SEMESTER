#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

main()
{
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;

char buff[MAXSIZE];
int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(8888);
serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==1)
{
printf("Binding error");
close(sockfd);
}

retval=listen(sockfd,1);
if(retval==-1)
{
close(sockfd);
}

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


if(newsockfd==-1)
{
close(sockfd);
}

 
int pid=fork();
if (pid!=0) 
{
printf("I'm the parent process with PID %d and PPID %d.\n",
getpid(),getppid());
printf("My child's PID is %d.\n", pid);
while(1){

strcpy(buff,"");
scanf("%s",buff);


sentbytes=send(newsockfd,buff,sizeof(buff),0);
if(strcmp(buff,"bye")==0)
{
close(sockfd);
close(newsockfd);
exit(0);
break;
}
if(sentbytes==-1)
{
printf("!!");
close(sockfd);
close(newsockfd);
}
}
}
else 
{
printf("I'm the child process with PID %d and PPID %d.\n",
getpid(),getppid());
while(1){

strcpy(buff,"");


recedbytes=recv(newsockfd,buff,sizeof(buff),0);
if(strcmp(buff,"bye")==0)
{
printf("Bye");
close(sockfd);
close(newsockfd);
exit(0);
break;
}
printf("Received message: ");
puts(buff);
}
printf("Byeeee\n");
close(sockfd);
close(newsockfd);
}
}
