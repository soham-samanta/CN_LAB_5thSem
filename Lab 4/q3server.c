#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <unistd.h>

int main()
{
    int sockfd,fd1,fd2,length,i;
    char buf[100]="\0";
    struct sockaddr_in sa,ta1;

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    sa.sin_family=AF_INET;
    sa.sin_addr.s_addr=INADDR_ANY;
    sa.sin_port=60018;

    i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));

    listen(sockfd,5);

    length=sizeof(sa);
    fd1=accept(sockfd,(struct sockaddr *) &ta1,&length);
    fd2=accept(sockfd,(struct sockaddr *) &ta1,&length);

    for(int j=0;j<5;j++)
	{
        recv(fd1,buf,100,0);
        send(fd2,buf,100,0);
        recv(fd2,buf,100,0);
        send(fd1,buf,100,0);
		if(strcmp(buf,"exit")==0 || strcmp(buf,"EXIT")==0){
            close(fd1);
            close(fd2);
            return 0;
        }
	}

    return 0;
}
