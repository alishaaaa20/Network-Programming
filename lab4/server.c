#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<time.h>
#define MAXLINE 1024
#define LISTENQ 10
typedef struct sockaddr SA;

int main(int argc,char **argv){
int listenfd,connfd;
char buff[MAXLINE];
time_t ticks;
socklen_t len;
struct sockaddr_in servaddr,cliaddr;
int port;

listenfd=socket(AF_INET,SOCK_STREAM,0);
port= atoi(argv[1]);
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr =htonl(INADDR_ANY);
servaddr.sin_port= htons(port);


if (bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
}
printf("server is waiting connection at port 12345\n ");
listen(listenfd,LISTENQ);
len=sizeof(cliaddr);
connfd=accept(listenfd,(SA *) &cliaddr,&len);
printf("connection from %s ,port %d\n",inet_ntop(AF_INET,&cliaddr.sin_addr, buff,sizeof(buff)),ntohs(cliaddr.sin_port));
    
while(1){
   printf("Enter a message: \n");
         memset(text,0,sizeof(text));
        fgets(text, 50, stdin);

        printf
  
  read(connfd,buff,MAXLINE);
  printf("From Client:\n");
  fputs(buff,stdout);
  write(connfd,buff,strlen(buff));
  
  }
  }