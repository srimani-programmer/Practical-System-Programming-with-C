// Client-Server Appication Client Code.
#include <stdio.h> 
#include <stdlib.h> 
#include<unistd.h>
#include <string.h> 
#include <sys/socket.h> 
#include <netdb.h> 
#include <arpa/inet.h>

#define MAX 1024 // Maximum number of data that can transfer
#define PORT 8080 // port number to connect
#define SA struct sockaddr // Creating Macro for the socketaddr as SA

// Function designed for chat between client and server. 
void communicate(int sockfd) { 
    char buff[MAX]; 
    int n; 
    while(1){ 

        bzero(buff, sizeof(buff)); 
        printf("Enter the message : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
            ;
        
        if ((strncmp(buff, "exit", 4)) == 0) { 
            char message[4] = "exit";
            write(sockfd, message, sizeof(message)); 
            printf("Client Exit.\n"); 
            break; 
        } 

        if ((strncmp(buff, "quit", 4)) == 0) { 
            char message[4] = "quit";
            write(sockfd, message, sizeof(message)); 
            printf("Client Exit.\n"); 
            break; 
        } 

        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 

        // Exit Condition for Client
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit.\n"); 
            break; 
        } 

        if ((strncmp(buff, "quit", 4)) == 0) { 
            printf("Client Exit.\n"); 
            break; 
        } 
    } 
} 
  
int main() { 

    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket creation and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 

    bzero(&servaddr, sizeof(servaddr)); 
  
    // Assigning IPAddress, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
  
    // function for chat 
    communicate(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 