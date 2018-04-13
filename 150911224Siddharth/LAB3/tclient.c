#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 90

main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
char buff[MAXSIZE];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(8888);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");
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


sentbytes=send(sockfd,buff,sizeof(buff),0);
if(strcmp(buff,"bye")==0)
{
close(sockfd);
exit(0);
break;
}
if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}
}
}
else 
{
printf("I'm the child process with PID %d and PPID %d.\n",
getpid(),getppid());
while(1){

strcpy(buff,"");


recedbytes=recv(sockfd,buff,sizeof(buff),0);
if(strcmp(buff,"bye")==0)
{
printf("Bye");
close(sockfd);
exit(0);
break;
}
printf("Received message: ");
puts(buff);
}
printf("Byeeee\n");
close(sockfd);
}
}

