#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int i,sockfd,n;
    char buf[100]="\0";
    struct sockaddr_in sa;
    
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=60018;

    i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));

    for(int j=0;j<5;j++)
	{
        recv(sockfd,&n,4,0);
        printf("Client 1 Number Received: %d\n\n",n);
        printf("Enter Number: ");
		scanf("%d",&n);
        send(sockfd,&n,4,0);
	}
    
    return 0;
}