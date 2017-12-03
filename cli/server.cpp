#include<stdio.h>
#include<string.h>    
#include<sys/socket.h>
#include<arpa/inet.h> 
#include<unistd.h>    
#include<iostream>
#define PORT 9092
int main(int argc , char *argv[])
{
    int sockd , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char *command;

    sockd = socket(AF_INET , SOCK_STREAM , 0);
    if (sockd == -1)
    {
        printf("Socket Creation Error . ! ");
    }
    puts("Socket object created");
     
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( PORT );
     
    //Bind
    if( bind(sockd,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("BIND failed. Errror");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(sockd , 3);
     
    puts("KeyValue Store v1.0 is waiting  for connection    . ");
    c = sizeof(struct sockaddr_in);
     
    client_sock = accept(sockd, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
     
    while( (read_size = recv(client_sock , command , 2000 , 0)) > 0 )
    {
        if(*command == 'get'){
            write( client_sock , "GET_METHOD" , 1000); //hash table get method

        }


        write(client_sock , "METHOD_EXCEPTION_MESSAGE" , strlen(command));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);

    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
     
    return 0;
}