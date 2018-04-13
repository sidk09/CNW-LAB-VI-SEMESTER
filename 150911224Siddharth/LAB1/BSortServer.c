#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

void bsort(int a[],int n)
{	
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
					{
						int temp=a[j];
						a[j]=a[j+1];
						a[j+1]=temp;
					}	
			}
}

void main()
{
int sockfd,newsockfd,retval,n;
socklen_t actuallen;
int recedbytes,sentbytes,flag=1;
struct sockaddr_in serveraddr,clientaddr;


//Data type to edit
int buff[MAXSIZE];

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
recedbytes=recv(newsockfd,&n,sizeof(n),0);
recedbytes=recv(newsockfd,buff,sizeof(buff),0);

if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}


 
//Start of Area to edit

//puts(buff);
//printf("\n");
//scanf("%s",buff);
bsort(buff,n);

sentbytes=send(newsockfd,buff,sizeof(buff),0);

//End of area

if(sentbytes==-1)
{
close(sockfd);
close(newsockfd);
}

close(sockfd);
close(newsockfd);


}

