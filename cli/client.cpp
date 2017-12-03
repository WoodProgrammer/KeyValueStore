#include<stdio.h> 
#include<string.h>   
#include<sys/socket.h>   
#include<arpa/inet.h> 
#include<unistd.h>  
#include<iostream>
#define PORT 9092

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char command[1000] , server_reply[2000];
    char host[100];

    
    if (argv[1] == NULL){
        strcpy(host,"127.0.0.1");
    }
    else{
        strcpy(host,"127.0.0.1");
    }
    
 
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons( PORT );
 
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    while(1)
    {
        printf("> : ");
        scanf("%s" , command);
         
        if( send(sock , command , strlen(command) , 0) < 0)
        {
            puts("CommandSend Failed ");
            return 1;
        }
         
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("Server receiving failed ! ");
            break;
        }
         
        puts("> :");
        puts(server_reply);
    }
     

    close(sock);
    return 0;

}