#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

int main()
{
    int i,sockfd;
    char buf[100]="\0";
    struct sockaddr_in sa;
    
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=inet_addr("127.0.0.1");
    sa.sin_port=60018;

    i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));

    recv(sockfd,buf,100,0);
    printf("%s\n",buf);

    for(int j=0;j<5;j++)
	{
        recv(sockfd,buf,100,0);
        printf("Client 1 string: %s\n\n",buf);
        if(strcmp(buf,"exit")==0 || strcmp(buf,"EXIT")==0){
            close(sockfd);
            return 0;
        }
        printf("Enter String: ");
		scanf("%s",buf);
        send(sockfd,buf,100,0);
	}
    
    return 0;
}
