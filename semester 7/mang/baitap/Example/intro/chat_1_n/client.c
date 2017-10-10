// BY Do Manh Hung - k59 - 20142062
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>

int socket_OK=0;


void sigpipe_handler();


int main(int argc, char *argv[]) {

    int sockfd, portno, n;
    struct sockaddr_in sAddr;
    struct hostent *server;

    char buffer[256];

    if(argc < 3) {
        fprintf(stderr, "usage: %s HOSTNAME PORT\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR OPENING SOCKET");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if(server == NULL) {
        fprintf(stderr, "ERROR, NO SUCH HOST\n", argv[0]);
        exit(0);
    }

    bzero((char *) &sAddr, sizeof(sAddr));

    sAddr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &sAddr.sin_addr.s_addr, server->h_length);
    sAddr.sin_port = htons(portno);
    
    signal(SIGPIPE,sigpipe_handler);

    if(connect(sockfd, (struct sockaddr*)&sAddr, sizeof(sAddr)) < 0) {
        perror("ERROR CONNECTING");
        exit(1);
    }

    socket_OK=1;

    while(1) {
        if(!socket_OK)    break;
        printf("To server: ");
        bzero(buffer, 256);
        if (fgets(buffer, 255, stdin) == NULL) {
            perror("ERROR CREATE TO BUFFET");
            exit(1);
        }

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            close(sockfd);
            printf("DISCONECT\n");
            perror("ERROR SEND REQUEST");
            exit(1);
        }

        bzero(buffer,256);

        if (recv(sockfd, buffer, 255, 0) < 0) {
            perror("ERROR RECEIVE RESPONSE");
            exit(1);
        }

        printf("From server: %s\n\n", buffer);
    }

    return 0;
}

void sigpipe_handler()
{
    printf("SIGPIPE caught\n");
    socket_OK=0;
}