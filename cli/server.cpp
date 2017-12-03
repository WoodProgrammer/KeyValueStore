#include<iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>





#define PORT 1000
#define BACKLOG 10

int main(){
    int client,server;
    bool is_exist = false;
    int buffer_size = 1024;
    char *message;


    struct sockaddr_in server_addr;
    socklen_t size;

    //init socket
    client = socket(AF_INET,SOCK_STREAM,0);

    if(client < 0 ){
        std::cout << "Error to create socket object \n"; 
    }else{
        std::cout << "Socket Object Created ! \n";
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY); //network byte converting.
    server_addr.sin_port = htons(PORT);//network byte converting.


    if( bind( client ,  (struct sockaddr*)&server_addr  ,sizeof(server_addr) ) <0 )  {
        std::cout << "Server  is binding \n ";
    }
    else{
        std::cout << "Server cannot binding \n ";
    }
    //bind controlling 

    size = sizeof(server_addr);

    listen(client,1);

    server = accept(client,(struct sockaddr*)&server_addr,&size);
    if(server < 0 ){
        std::cout <<"Error cannot serving ."; 


    }else{
        std::cout <<"Serving"; 

    }
    while (server > 0){
        strcpy(message,"Server Connected \n");
        send(server,message,buffer_size,0);
        std::cout << "Connected with client "<<client;
        do {
            recv(server,message,buffer_size,0);


        }while(message == "e");
    }
}