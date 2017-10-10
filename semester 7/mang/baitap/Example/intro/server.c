// BY Do Manh Hung - k59 - 20142062
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PORT 88881

void convertToUpperCase(char *sPtr);
int doIt(int sock);

////////
int main(int argc, char const *argv[]) {

    int sockfd, newSockfd, childcount = 0;
    pid_t pid;
    socklen_t cLen;
    char buffer[256];
    
    struct sockaddr_in sAddr, cAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR OPENING SOCKET");
        exit(1);
    }

    bzero((char*) &sAddr, sizeof(sAddr));

    sAddr.sin_family = AF_INET; 
    sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sAddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &sAddr, sizeof(sAddr)) < 0) {
        perror("ERROR ON BINDING");
        exit(1);
    }

    if (listen(sockfd, 1000) < 0){
        perror("ERROR LISTEN PORT");
        exit(1);
    };

    printf("Linsten on port: %d\n", PORT);
    fflush(stdout);

    while(1) {
        cLen = sizeof(cAddr);
        newSockfd = accept(sockfd, (struct sockaddr *) &cAddr, &cLen);

        if (newSockfd < 0)  {
            perror("ERROR ON ACCEPT");
            exit(1);
        }

        pid = fork();

        if (pid < 0) {
            perror("ERROR ON FORK");
            exit(1);
        } else if (pid == 0) {
            // bzero(buffer, 256);
            close(sockfd);
            
            while(1) {
                if (doIt(newSockfd) < 0) {
                    close(newSockfd);
                    exit(0);
                };
            }

            close(newSockfd);
            exit(0);
        }

        printf("\n-------PROCESS ID: %d\n", pid);
        childcount++;
        while(childcount){
            pid = waitpid( (pid_t) - 1, NULL, WNOHANG );
            if (pid < 0) perror("ERROR WAIT PROCESS");
            else if (pid == 0) break;
            else childcount--;
        } 
    }
    
    close(sockfd);
    return 0;
}
/////////


void convertToUpperCase(char *sPtr) {   
    while(*sPtr != '\0')  {
        if (islower(*sPtr))
            *sPtr = toupper((unsigned char)*sPtr);
        *sPtr++;
    }
}

int doIt(int sock) {
    int n;
    char buffer[256], upperBuffer[256];
    bzero(buffer, 256);

    n = read(sock, (char*)&buffer, 255);

    if (n < 0) {
        perror("ERROR READING FROM SOCKET");
        exit(1);
    }

    buffer[n-1] = '\0';

    if (strcmp(buffer,"END") == 0) {
        printf("\n\tFrom client: END\n");
        printf("\tTo client:   DISCONECT\n");
        n = write(sock, "DISCONECT", strlen("DISCONECT"));

        if (n < 0) {
            perror("ERROR WRITING TO SOCKET");
            exit(1);
        }
        return -1;
    } else {
        strcpy(upperBuffer, buffer);
        printf("\n\tFrom client: %s\n",upperBuffer);

        convertToUpperCase(upperBuffer);

        printf("\tTo client:   %s\n",upperBuffer);

        n = write(sock, upperBuffer, strlen(upperBuffer));
        if (n < 0) {
            perror("ERROR WRITING TO SOCKET");
            exit(1);
        }
        return 0;
    }
}