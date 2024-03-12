#include<time.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#define MAXLINE 1024
#define LISTENQ 10
typedef struct sockaddr SA;

int main(int argc,char **argv)
{
  int listenfd,connfd;
  struct sockaddr_in servaddr,cliaddr;
  char buff[MAXLINE];
  time_t ticks;
  socklen_t len;
  int port;
  listenfd=socket(AF_INET,SOCK_STREAM,0);
  port=atoi(argv[1]);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  servaddr.sin_port=htons(port);/*daytime server*/
if (bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
}
printf("server is waiting connection at port 12345\n");
  listen(listenfd,LISTENQ);
 
  for(;;)
  {
    //connfd=accept(listenfd,(SA *)NULL,NULL);
    //printf("clientconnected"!\n);
    len=sizeof(cliaddr);
    connfd=accept(listenfd,(SA *)&cliaddr,&len);
    printf("connection from %s,port %d\n",
inet_ntop(AF_INET,&cliaddr.sin_addr,buff,sizeof(buff)),ntohs(cliaddr.sin_port));
    ticks=time(NULL);
    snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
    write(connfd,buff,strlen(buff));
    close(connfd);
  }
}