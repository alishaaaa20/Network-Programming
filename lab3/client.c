#include <time.h>
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
# define LISTENQ 10
typedef struct sockaddr SA;
int main(int argc,char **argv){
int sockfd,n;
 
  char recvline[MAXLINE +1];
  char buff[MAXLINE];
  struct sockaddr_in servaddr;
  int port;
 
  if (argc!=3)
    printf("usage:a.out<IPaddress><port>");
   
  if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
    printf("SOCKET ERROR");
  port=atoi(argv[2]);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(port);
   
    if (inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
      printf("inet_pton error for %s",argv[1]);
     
    if (connect(sockfd,(SA *) &servaddr,sizeof(servaddr))<0)
      printf("connect errror");
     
    while(1) {
        printf("Enter a message: \n");
        fgets(recvline, MAXLINE, stdin);
         write(sockfd,recvline,strlen(recvline));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, MAXLINE);
        printf("Received from server: \n");
        fputs(buff, stdout);

        if(n<0)
            printf("read errror");
      
      
     exit(0);
    }
}