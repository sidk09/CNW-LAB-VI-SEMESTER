#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 500


int main()
{

int sockfd,retval,ch[MAXSIZE],port,x[MAXSIZE],y[MAXSIZE];
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
char buff[MAXSIZE],search[MAXSIZE];
char message[MAXSIZE],msg2[MAXSIZE],msg3[MAXSIZE];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}

printf("Enter port number\n");
scanf("%d",&port);
printf("%i",sockfd);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");

}

while(1){
printf("Enter from one of the below options:\n");
int i;
printf("1-Book Tickets\n");
//printf("1-Insert new book information\n");
//printf("2-Delete a book\n");
//printf("3-Display all book information\n");
//printf("4-Search a book(Title/Author)\n");
printf("2-Exit\n");

scanf("%d",&ch[0]);
if (ch[0]==2){
sentbytes=send(sockfd,ch,sizeof(ch),0);
printf("Bye!");
close(sockfd);
break;
}
else{
sentbytes=send(sockfd,ch,sizeof(ch),0);
/*
if (ch[0]==1){

printf("Enter title:\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Enter author:\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Enter publisher:\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Enter number of pages:\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Enter accession number:\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Servers response:\n");

recedbytes=recv(sockfd,message,sizeof(message),0);
puts(message);
printf("\n");

}


if (ch[0]==2){

printf("Enter accNo:\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Servers response:\n");

recedbytes=recv(sockfd,message,sizeof(message),0);
puts(message);
printf("\n");



}


if (ch[0]==4){

printf("Enter title\n");
scanf("%s",buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);

printf("Servers response:\n");

recedbytes=recv(sockfd,msg2,sizeof(msg2),0);
puts(msg2);
printf("\n");


}



*/
if (ch[0]==1){
printf("Servers response:\n");

recedbytes=recv(sockfd,msg2,sizeof(msg2),0);
puts(msg2);
printf("\n");


printf("Enter from (1-5) Select Movie:\n");
int i;
scanf("%d",&ch[0]);

sentbytes=send(sockfd,ch,sizeof(ch),0);

if (ch[0]==1){
printf("Servers response:\n");

recedbytes=recv(sockfd,msg3,sizeof(msg2),0);
puts(msg2);
printf("\n");

printf("Enter time:\n");
scanf("%d",&ch[0]);
printf("Enter Seats:\n");
scanf("%d",&ch[0]);
sentbytes=send(sockfd,ch,sizeof(ch),0);
printf("Successfully Booked !!!");
close(sockfd);
}

if (ch[0]==2){
printf("Servers response:\n");

recedbytes=recv(sockfd,msg2,sizeof(msg2),0);
puts(msg2);
printf("\n");
printf("Enter time:\n");
scanf("%d",&ch[0]);
printf("Enter Seats:\n");
scanf("%d",&ch[0]);
printf("Successfully Booked !!!");
sentbytes=send(sockfd,ch,sizeof(ch),0);


close(sockfd);
}

if (ch[0]==3){
printf("Servers response:\n");

recedbytes=recv(sockfd,msg2,sizeof(msg2),0);
puts(msg2);
printf("\n");
printf("Enter time:\n");
scanf("%d",&ch[0]);
printf("Enter Seats:\n");
scanf("%d",&ch[0]);
printf("Successfully Booked !!!");
sentbytes=send(sockfd,ch,sizeof(ch),0);
close(sockfd);
}

if (ch[0]==4){
printf("Servers response:\n");

recedbytes=recv(sockfd,msg2,sizeof(msg2),0);
puts(msg2);
printf("\n");

close(sockfd);
}

if (ch[0]==5){
printf("Servers response:\n");

recedbytes=recv(sockfd,msg2,sizeof(msg2),0);
puts(msg2);
printf("\n");
close(sockfd);
}















}



if (strcmp(message,"bye")==0){
close(sockfd);
break;
}

}

}
}
