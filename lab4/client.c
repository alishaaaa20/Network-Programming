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

 
  char text[MAXLINE +1];
  int sockfd;
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

        printf("From server: \n");
        memset(text,0,sizeof(text));
        read(sockfd, text, MAXLINE);
        fputs(text, stdout);



        printf("Enter a message: \n");
         memset(text,0,sizeof(text));
        fgets(text, 50, stdin);
         write(sockfd,text,strlen(text));
      
    }
}