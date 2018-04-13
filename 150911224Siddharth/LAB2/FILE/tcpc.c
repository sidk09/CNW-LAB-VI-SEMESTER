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
char buff[MAXSIZE], res;

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
char f[20];
	printf("Give the file name\n");
	scanf("%s",f);

//Send from Next Line
//sentbytes=send(sockfd,f,sizeof(f),0);





	
    int p;
    FILE *fp;
    char ch,str[100];
    printf("Press 1 if you want to write to file\nPress 2 if you want to read the file\nPress 3 if you want to search the file\n");
    scanf("%d",&p);
    
    
   
    
    
    
    
    
    if(p==1)
    {
    
    
    sentbytes=send(sockfd,&p,sizeof(p),0);
    sentbytes=send(sockfd,f,sizeof(f),0);
    printf("Enter data... \n");
    scanf("%s",buff);
    sentbytes=send(sockfd,buff,sizeof(buff),0);
    
    if(sentbytes==-1)
	{
	printf("!!");
	close(sockfd);
	}
    
    }
    else if(p==2){
    sentbytes=send(sockfd,&p,sizeof(p),0);
    sentbytes=send(sockfd,f,sizeof(f),0);
    
    
    }
    
    




recedbytes=recv(sockfd,buff,sizeof(buff),0);
puts(buff);

printf("\n");
close(sockfd);
}

