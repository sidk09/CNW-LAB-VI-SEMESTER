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
#include<vector>
#include<iostream>
#include<algorithm>
#define max 200
using namespace std;
class stud{
public:
	char sem[50],marks[3][50];
	char reg[50],name[50],address[50],dept[50],section[50],courses[3][50];
	void assign(char* r, char* s,char* n,char* add,char* dep,char* sec){
	strcpy(reg,r);strcpy(sem,s);strcpy(name,n);strcpy(address,add);strcpy(dept,dep);strcpy(section,sec);
	}
	void assign1(char* s1, char* s2, char* s3, char* m1, char* m2, char* m3){
	strcpy(courses[0] , s1);strcpy(courses[1] , s2);strcpy(courses[2] , s3);strcpy(marks[0],m1);strcpy(marks[1],m2);strcpy(marks[2],m3);
	}
};
int main()
{

	stud student[3];
	student[0].assign("100","6","RAJ","MANIPAL","IT","B");
	student[1].assign("1001","4","MAX","UDUPI","CCE","A");
	student[2].assign("1208","6","XYZ","BLR","CS","D");
	student[0].assign1("DS","EEFM","ES","80","53","97");
	student[1].assign1("DBS","EM","ES","85","67","98");
	student[2].assign1("DS","EEFM","DAA","81","39","77");

	int sockfd,newsockfd,k;
	socklen_t actuallen;
	int retval;
int choice[1];
	size_t leng;
	char c;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;
	char buff[max],temp[max];
char buff1[max];
	int a=0;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\n Socket creation error");
		exit(0);
	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3380);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3381);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("\n Binding error");
		close(sockfd);
	 	exit(0);
	}
	actuallen=sizeof(clientaddr);
	retval=recvfrom(sockfd,choice,sizeof(choice),0,(struct sockaddr *)&clientaddr,&actuallen);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}
	actuallen=sizeof(clientaddr);
	retval=recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&clientaddr,&actuallen);
	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}

////////
int i;
switch (choice[0])
{
case 1:
for(i=0;i<3;i++)
{
if(strcmp(student[i].reg,buff)==0)
{
cout<<student[i].name<<endl;
cout<<student[i].address<<endl;
strcpy(buff1,"");
strcat(buff1,student[i].name);strcat(buff1,"\n");
strcat(buff1,student[i].address);strcat(buff1,"\n");
puts(buff1);
//retval=sendto(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&clientaddr,actuallen);
break;
}
}
if(i==3)
{
cout<<"Not Found"<<endl;
strcpy(buff1,"Not Found");
}
break;
case 2:
for(i=0;i<3;i++)
{
if(strcmp(student[i].name,buff)==0)
{
cout<<student[i].dept<<endl;
cout<<student[i].sem<<endl;
cout<<student[i].section<<endl;
strcpy(buff1,"");
strcat(buff1,student[i].dept);strcat(buff1,"\n");
strcat(buff1,student[i].sem);strcat(buff1,"\n");
strcat(buff1,student[i].section);strcat(buff1,"\n");
//retval=sendto(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&clientaddr,actuallen);
strcat(buff1,"Courses");strcat(buff1,"\n");
for(int j=0;j<3;j++)
{
	cout<<"Course: "<<student[i].courses[j]<<endl;
	strcat(buff1,student[i].courses[j]);strcat(buff1,"\n");
}
break;
}
}
if(i==3)
{
cout<<"Not Found"<<endl;
strcpy(buff1,"Not Found");
}
break;
case 3:
strcpy(buff1,"");
for(i=0;i<3;i++)
{
	for(int j=0;j<3;j++)
	{
	if(strcmp(student[i].courses[j],buff)==0)
	{
	cout<<student[i].name<<": "<<student[i].marks[j]<<endl;

	strcat(buff1,student[i].name);strcat(buff1,"\n");
	strcat(buff1,student[i].marks[j]);strcat(buff1,"\n");
	//retval=sendto(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&clientaddr,actuallen);
	}

}}
if(strcmp(buff1,"")==0)
{
cout<<"Not Found"<<endl;
strcpy(buff1,"Not Found");
}

break;
}
	retval=sendto(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&clientaddr,actuallen);
	printf("\n");

	if(retval==-1)
	{
		close(sockfd);
		exit(0);
	}

	close(sockfd);
}

