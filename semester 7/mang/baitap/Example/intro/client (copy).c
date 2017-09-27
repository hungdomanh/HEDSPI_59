// // BY Do Manh Hung - k59 - 20142062
// #include <sys/socket.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <netdb.h>
// #include <netinet/in.h>
// #include <string.h>
// #include <ctype.h>
// #include <unistd.h>


// int main(int argc, char *argv[]) {

//     int sockfd, portno, n;
//     struct sockaddr_in sAddr;
//     struct hostent *server;

//     char buffer[256];

//     if(argc < 3) {
//         fprintf(stderr, "usage: %s HOSTNAME PORT\n", argv[0]);
//         exit(0);
//     }

//     portno = atoi(argv[2]);

//     sockfd = socket(AF_INET, SOCK_STREAM, 0);

//     if (sockfd < 0) {
//         perror("ERROR OPENING SOCKET");
//         exit(1);
//     }

//     server = gethostbyname(argv[1]);

//     if(server == NULL) {
//         fprintf(stderr, "ERROR, NO SUCH HOST\n", argv[0]);
//         exit(0);
//     }

//     bzero((char *) &sAddr, sizeof(sAddr));

//     sAddr.sin_family = AF_INET;
//     bcopy((char*) server->h_addr, (char*) &sAddr.sin_addr.s_addr, server->h_length);
//     sAddr.sin_port = htons(portno);
    
//     if(connect(sockfd, (struct sockaddr*)&sAddr, sizeof(sAddr)) < 0) {
//         perror("ERROR CONNECTING");
//         exit(1);
//     }

//     while(1) {
//         printf("Send the message: ");
//         bzero(buffer, 256);
//         if (fgets(buffer, 255, stdin) == NULL)
//         {
//             perror("ERROR CREATE TO BUFFET");
//             exit(1);
//         }

//         if (send(sockfd, buffer, strlen(buffer), 0) < 0)
//         {
//             perror("ERROR SEND REQUEST");
//             exit(1);
//         }

//         bzero(buffer,256);

//         if (recv(sockfd, buffer, 255, 0) < 0)
//         {
//             perror("ERROR RECEIVE RESPONSE");
//             exit(1);
//         }

//         printf("%s\n", buffer);
//     }

//     return 0;
// }


#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 5550
#define BUFF_SIZE 8192

int main(){
    int client_sock;
    char buff[BUFF_SIZE];
    struct sockaddr_in server_addr; /* server's address information */
    int msg_len, bytes_sent, bytes_received;
    
    //Step 1: Construct socket
    client_sock = socket(AF_INET,SOCK_STREAM,0);
    
    //Step 2: Specify server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    
    //Step 3: Request to connect server
    if(connect(client_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0){
        printf("\nError!Can not connect to sever! Client exit imediately! ");
        return 0;
    }
        
    //Step 4: Communicate with server           
    while(1){
        //send message
        printf("\nInsert string to send:");
        memset(buff,'\0',(strlen(buff)+1));
        fgets(buff, BUFF_SIZE, stdin);      
        msg_len = strlen(buff);
        if (msg_len == 0) break;
        
        bytes_sent = send(client_sock, buff, msg_len, 0);
        if(bytes_sent <= 0){
            printf("\nConnection closed!\n");
            break;
        }
        
        //receive echo reply
        bytes_received = recv(client_sock, buff, BUFF_SIZE-1, 0);
        if(bytes_received <= 0){
            printf("\nError!Cannot receive data from sever!\n");
            break;
        }
        
        buff[bytes_received] = '\0';
        printf("Reply from server: %s", buff);
    }
    
    //Step 4: Close socket
    close(client_sock);
    return 0;
}

