#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 500


struct Movie{
char title[100];
char timing1[100],timing2[100];
char seats[100];
};


int main()
{
struct Movie s1[10];

strcpy(s1[0].title,"1. B Panther");
strcpy(s1[0].timing1,"1pm");
strcpy(s1[0].timing2,"3pm");
strcpy(s1[0].seats,"50");


strcpy(s1[1].title,"2. SKTS");
strcpy(s1[1].timing1,"2pm");
strcpy(s1[1].timing2,"5pm");
strcpy(s1[1].seats,"55");



strcpy(s1[2].title,"3. SOTY");
strcpy(s1[2].timing1,"2pm");
strcpy(s1[2].timing2,"5pm");
strcpy(s1[2].seats,"50");

strcpy(s1[3].title,"4. A Pie");
strcpy(s1[3].timing1,"1pm");
strcpy(s1[3].timing2,"3pm");
strcpy(s1[3].seats,"50");

strcpy(s1[4].title,"5. Avenger");
strcpy(s1[4].timing1,"1pm");
strcpy(s1[4].timing2,"3pm");
strcpy(s1[4].seats,"50");





int newi=5;

int i;

int sockfd,newsockfd,retval,port;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;
char buff[MAXSIZE];
int key[MAXSIZE],flag=0,ch[MAXSIZE];
char msg[MAXSIZE],msg2[MAXSIZE];
int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}
printf("Enter port number\n");
scanf("%d",&port);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(port);
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
printf("err");
close(sockfd);
}

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


if(newsockfd==-1)
{
close(sockfd);
}

//while(1){
recedbytes=recv(newsockfd,ch,sizeof(ch),0);

if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
printf("Choice not received");
}
printf("\n");

/*
if (ch[0]==1){

}
	
}

*/
if (ch[0]==1){
strcpy(msg,"Movie Name: ");
for(i=0;i<newi;i++){
	strcat(msg,&(s1[i].title));
	strcat(msg,"\n");
	
	
	
	if (i!=(newi-1))
	strcat(msg,"Movie name: ");
	}
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
	if(sentbytes==-1)
	{
	printf("Problem in sending!");
	close(sockfd);
	close(newsockfd);
	}
	
	
	
	recedbytes=recv(newsockfd,ch,sizeof(ch),0);
	if (ch[0]==1){
	printf(s1[0].title);
	printf("\n");
	strcat(msg,&(s1[0].timing1));
	strcat(msg,"\n");
	strcat(msg,&(s1[0].timing2));
	strcat(msg,"\n");
	strcat(msg,&(s1[0].seats));
	printf((s1[0].seats)-8);
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
	printf("42");
	
	
	}
	if (ch[0]==2){
	printf(s1[1].title);
	printf("\n");
	printf("\n");
	strcat(msg,&(s1[1].timing1));
	strcat(msg,"\n");
	strcat(msg,&(s1[1].timing2));
	strcat(msg,"\n");
	strcat(msg,&(s1[1].seats));
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
	printf("47");
	}
	if (ch[0]==3){
	printf(s1[2].title);
	printf("\n");
	printf("\n");
	strcat(msg,&(s1[2].timing1));
	strcat(msg,"\n");
	strcat(msg,&(s1[2].timing2));
	strcat(msg,"\n");
	strcat(msg,&(s1[2].seats));
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
	printf("42");
	}
	if (ch[0]==4){
	printf(s1[3].title);
	printf("\n");
	printf("\n");
	strcat(msg,&(s1[3].timing1));
	strcat(msg,"\n");
	strcat(msg,&(s1[3].timing2));
	strcat(msg,"\n");
	strcat(msg,&(s1[3].seats));
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
	printf("42");
	
	}
	if (ch[0]==5){
	printf(s1[4].title);
	printf("\n");
	printf("\n");
	strcat(msg,&(s1[4].timing1));
	strcat(msg,"\n");
	strcat(msg,&(s1[4].timing2));
	strcat(msg,"\n");
	strcat(msg,&(s1[4].seats));
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
	printf("42");
	}
	
	
	
	
	
	
}




if (ch[0]==2){
close(sockfd);
close(newsockfd);
//break;
}



//}
if (flag==0){
	strcpy(msg,"No such record!");
	sentbytes=send(newsockfd,msg,sizeof(msg),0);
}
close(sockfd);
close(newsockfd);
}

