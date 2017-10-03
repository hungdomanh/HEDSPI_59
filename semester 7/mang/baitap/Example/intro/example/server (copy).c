// // BY Do Manh Hung - k59 - 20142062
// #include <sys/socket.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <netdb.h>
// #include <netinet/in.h>
// #include <string.h>
// #include <ctype.h>
// #include <unistd.h>


// #define PORT 8888

// void convertToUpperCase(char *sPtr);
// void doIt(int sock);

// ////////
// int main(int argc, char const *argv[]) {

//     int sockfd, cLen, newSockfd, pid;
//     char buffer[256];
    
//     struct sockaddr_in sAddr, cAddr;

//     sockfd = socket(AF_INET, SOCK_STREAM, 0);

//     if (sockfd < 0) {
//         perror("ERROR OPENING SOCKET");
//         exit(1);
//     }

//     bzero((char*) &sAddr, sizeof(sAddr));

//     sAddr.sin_family = AF_INET; 
//     sAddr.sin_addr.s_addr = INADDR_ANY;
//     sAddr.sin_port = htons(PORT);
//     printf("Linsten on port: %d\n", PORT);

//     if (bind(sockfd, (struct sockaddr *) &sAddr, sizeof(sAddr)) < 0) {
//         perror("ERROR ON BINDING");
//         exit(1);
//     }


//     listen(sockfd, 1000);
//     cLen = sizeof(cAddr);

//     while(1) {
//         newSockfd = accept(sockfd, (struct sockaddr *) &cAddr, &cLen);

//         if (newSockfd < 0)
//         {
//             perror("ERROR ON ACCEPT");
//             exit(1);
//         }

//         pid = fork();

//         if (pid < 0)
//         {
//             perror("ERROR ON FORK");
//             exit(1);
//         }

//         if (pid == 0)
//         {
//             // bzero(buffer, 256);
//             // close(sockfd);
//             doIt(newSockfd);
//             // exit(0);

//         } else {
//             close(newSockfd);
//         }
//     }

//     return 0;
// }
// /////////

// void convertToUpperCase(char *sPtr) {   
//     while(*sPtr != '\0')  {
//         if (islower(*sPtr))
//             *sPtr = toupper((unsigned char)*sPtr);
//         *sPtr++;
//     }
// }

// void doIt(int sock) {
//     int n;
//     char buffer[256], upperBuffer[256];
//     bzero(buffer, 256);

//     n = read(sock, buffer, 255);

//     if (n < 0) {
//         perror("ERROR READING FROM SOCKET");
//         exit(1);
//     }

//     strcpy(upperBuffer, buffer);
//     printf("Here is the message: %s",upperBuffer);

//     convertToUpperCase(upperBuffer);

//     printf("Here is the UPPER message: %s\n",upperBuffer);

//     // n = write(sock, "Here is the UPPER message: ", 27);
//     // if (n < 0) {
//     //     perror("ERROR WRITING TO SOCKET");
//     //     exit(1);
//     // }

//     // n = write(sock, upperBuffer, 1000);
//     // if (n < 0) {
//     //     perror("ERROR WRITING TO SOCKET");
//     //     exit(1);
//     // }

//     if (send(sock, upperBuffer, 1000, 0) < 0)
//     {
//         perror("ERROR SEND REQUEST");
//         exit(1);
//     }

// }


#include <stdio.h>          /* These are the usual header files */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 5550   /* Port that will be opened */ 
#define BACKLOG 20  /* Number of allowed connections */
#define BUFF_SIZE 1024

int main()
{
 
    int listen_sock, conn_sock; /* file descriptors */
    char recv_data[BUFF_SIZE];
    int bytes_sent, bytes_received;
    struct sockaddr_in server; /* server's address information */
    struct sockaddr_in client; /* client's address information */
    int sin_size;
    
    //Step 1: Construct a TCP socket to listen connection request
    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){  /* calls socket() */
        perror("\nError: ");
        return 0;
    }
    
    //Step 2: Bind address to socket
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;         
    server.sin_port = htons(PORT);   /* Remember htons() from "Conversions" section? =) */
    server.sin_addr.s_addr = htonl(INADDR_ANY);  /* INADDR_ANY puts your IP address automatically */   
    if(bind(listen_sock, (struct sockaddr*)&server, sizeof(server))==-1){ /* calls bind() */
        perror("\nError: ");
        return 0;
    }     
    
    //Step 3: Listen request from client
    if(listen(listen_sock, BACKLOG) == -1){  /* calls listen() */
        perror("\nError: ");
        return 0;
    }
    
    //Step 4: Communicate with client
    while(1){
        //accept request
        sin_size = sizeof(struct sockaddr_in);
        if ((conn_sock = accept(listen_sock,( struct sockaddr *)&client, &sin_size)) == -1) 
            perror("\nError: ");
  
        printf("You got a connection from %s\n", inet_ntoa(client.sin_addr) ); /* prints client's IP */
        
        //start conversation
        while(1){
            //receives message from client
            bytes_received = recv(conn_sock, recv_data, BUFF_SIZE-1, 0); //blocking
            if (bytes_received <= 0){
                printf("\nConnection closed");
                break;
            }
            else{
                recv_data[bytes_received] = '\0';
                printf("\nReceive: %s ", recv_data);
            }
            
            //echo to client
            bytes_sent = send(conn_sock, recv_data, bytes_received, 0); /* send to the client welcome message */
            if (bytes_sent <= 0){
                printf("\nConnection closed");
                break;
            }
        }//end conversation
        close(conn_sock);   
    }
    
    close(listen_sock);
    return 0;
}