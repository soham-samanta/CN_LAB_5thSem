#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int i,sockfd=0,roll,arr[5];
	char buf[100];
	struct sockaddr_in sa;

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=60018;

  	i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));

	printf("Enter Roll No.: ");
	scanf("%d",&roll);

	send(sockfd,&roll,4,0);

	if(recv(sockfd,buf,100,0)){
		printf("\nName: %s",buf);
		recv(sockfd,&roll,100,0);
		printf("\nRoll No.: %d",roll);

		printf("\nMarks: ");
		for(i=0;i<5;i++){
			recv(sockfd,&arr,5*sizeof(int),0);
			printf("%d ",arr[i]);
		}
	}

	else
		return 0; 

	close(sockfd);

	return 0; 
}