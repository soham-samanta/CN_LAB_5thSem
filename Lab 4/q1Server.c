#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

struct info
{
	char name[100];
	int roll,marks[5];
} s[10]=
{
	{"Snehil Sharma",2005545,{100,99,95,92,97}},
	{"a",2005546,{1,2,3,4,5}},
	{"b",2005547,{6,7,8,9,10}},
	{"c",2005548,{11,12,13,14,15}},
	{"d",2005549,{16,17,18,19,20}},
	{"e",2005550,{21,22,23,24,25}},
	{"f",2005551,{26,27,28,29,30}},
	{"g",2005552,{31,32,33,34,35}},
	{"h",2005553,{36,37,38,39,40}},
	{"i",2005554,{41,42,43,44,45}}
};

int main()
{
	int sockfd,fd1,i,j,length,r;
	struct sockaddr_in sa,ta1;

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=60018;

	i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));

	listen(sockfd,5);

	length=sizeof(sa);
 	fd1=accept(sockfd, (struct sockaddr *) &ta1,&length);

	recv(fd1,&r,4,0);

	for(i=0;i<10;i++){
		if(r==s[i].roll){
			send(fd1,s[i].name,100,0);
			send(fd1,&s[i].roll,4,0);
			for(j=0;j<5;j++)
				send(fd1,&s[i].marks,5*sizeof(int),0);
			close(fd1);
			return 0;
		}
	}

	close(fd1);

	return 0;
}