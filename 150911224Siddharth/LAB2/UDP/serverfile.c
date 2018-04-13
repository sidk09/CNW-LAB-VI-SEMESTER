#include <stdio.h>
#include<stdlib.h>
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
int sockfd,newsockfd,retval;
socklen_t actuallen;
char ch;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;
char buff[MAXSIZE][MAXSIZE];
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

recedbytes=recv(newsockfd,buff,sizeof(buff),0);
if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}
if (strcmp(buff[1],"1")==0)
	{
	FILE *fptr;
	fptr = fopen(buff[0], "r");
	if (fptr == NULL)
    		{
        	printf("Cannot open file %s\n ",buff[0]);
        	exit(0);
    		}
	strcpy(buff[0],"");
    	ch = fgetc(fptr);
	int j=0;
    	while (ch != EOF)
    		{
    	    	buff[0][j]=ch;
    	    	ch = fgetc(fptr);
		j++;
    		}
    	fclose(fptr);
	}
if (strcmp(buff[1],"2")==0)
	{
	FILE *fptw;
	fptw = fopen(buff[0], "a");
	 if (fptw == NULL)
    	{
        printf("File does not exists \n");
        return;
    	}
    	fprintf(fptw, "%s\n", buff[2]);
    	fclose(fptw);
	strcpy(buff[0],"Write Successful");
	}
sentbytes=send(newsockfd,buff,sizeof(buff),0);
if(sentbytes==-1)
{
close(sockfd);
close(newsockfd);
}

close(sockfd);
close(newsockfd);
}

