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
#define max 50
int main()
{       char b[20];
        int n,x,i,j,emp; 
	int sockfd,newsockfd,k;
	socklen_t actuallen;
	int retval;
	size_t leng;
	char c;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	char buff[max],temp[max];
	int a=0;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\n Socket creation error");
		exit(0);
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3391);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3392);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("\n Binding error");
		close(sockfd);
	 	exit(0);
	}
	actuallen=sizeof(clientaddr);
		retval=recvfrom(sockfd,b,sizeof(b),0,(struct sockaddr *)&clientaddr,&actuallen);	
		if(retval==-1)
		{
			close(sockfd);
			exit(0);
		}
		
		
		
		
		
		
		int p;
    FILE *fp;
    char ch,str[100];
    printf("Press 1 if you want to write to file\nPress 2 if you want to read the file\nPress 3 if you want to search the file\n");
    scanf("%d",&p);
    
    if(p==1)
    {
    fp = fopen(b, "w");
    printf("Enter data... \npress * to stop\n");
    while( (ch = getchar()) != '*') {
        putc(ch, fp);
    }
    fclose(fp);
    }
    
    else if(p==2)
    {
    fp = fopen(b, "r"); 
    while( (ch = getc(fp)) != EOF)
    {printf("%c",ch);}    
    fclose(fp);
    }
    
    
    else
    {printf("give string to be searched\n");
     scanf("%s",str);   
     
     fp = fopen(b, "r"); 
    while( (ch = getc(fp)) != EOF)
    {if(ch==str[i])
      {i++;}
      else{i=0;}
      if(i==strlen(str)){printf("the given string is present in the file :) \n"); fclose(fp); return;}}    
    fclose(fp);         
    printf("the given string is not present in the file :( \n");
    }
		
		
		
		
		
	

	close(sockfd);
}

