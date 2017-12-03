#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include<iostream>
#define PORT 5000
int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0,valread;
    struct sockaddr_in serv_addr; 
    char buffer[1024] = {0};
    char sendBuff[1025];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 
    if ((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL) )<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    while(connfd > 0){
        listen(listenfd, 10); 
        if ((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL) )<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
            
            
        }else{
            valread = read( connfd , buffer, 1024);
            std::cout<<buffer ;
        }
       
    }
     
}