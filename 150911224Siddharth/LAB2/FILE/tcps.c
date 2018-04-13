#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90



void main()
{char b[20];
 int i,p;
int sockfd,newsockfd,retval,n;
socklen_t actuallen;
int recedbytes,sentbytes,flag=1,x;
struct sockaddr_in serveraddr,clientaddr;


//Data type to edit
char buff[MAXSIZE];

int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
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

recedbytes=recv(newsockfd,&p,sizeof(p),0);


if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}

		
	if(p==1)
	{	
	recedbytes=recv(newsockfd,buff,sizeof(buff),0);
	
	FILE *fp;
	fp = fopen(buff, "w");
	
	recedbytes=recv(newsockfd,buff,sizeof(buff),0);
	for(i=0;i<strlen(buff);i++)
        putc(buff[i], fp);
        fclose(fp);
	
	
	}
	
	else if(p==2){
	recedbytes=recv(newsockfd,buff,sizeof(buff),0);
	
	FILE *fp;
	fp = fopen(buff, "r");
	
	char ch;
	while( (ch = getc(fp)) != EOF)
    {
    printf("%c",ch);
    }    
    
        
        fclose(fp);
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
close(sockfd);
close(newsockfd);


}


