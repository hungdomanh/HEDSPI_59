#include "transfer.h"

// Common
char* initBuffer() {
    char buffer[BUFFER_LENGTH];
    bzero(buffer, BUFFER_LENGTH);
    return buffer;
}
////
// Use in Client

void fromServer(int sock)
{
    char buffer[BUFFER_LENGTH];
    bzero(buffer, BUFFER_LENGTH);

    if (recv(sock, buffer, BUFFER_LENGTH - 1, 0) < 0)
    {
        perror("ERROR RECEIVE RESPONSE");
        exit(1);
    }

    printf("From server: %s\n\n", buffer);
    sendToServer(sock);
}

void toServer(int sock)
{
    char buffer[BUFFER_LENGTH];
    bzero(buffer, BUFFER_LENGTH);

    if (fgets(buffer, BUFFER_LENGTH - 1, stdin) == NULL)
    {
        perror("ERROR CREATE TO BUFFET");
        exit(1);
    }

    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        close(sock);
        printf("DISCONECT\n");
        perror("ERROR SEND REQUEST");
        exit(1);
    }
}

////
// Use in Server
char *fromClient(int sock)
{
    char buffer[BUFFER_LENGTH];
    bzero(buffer, BUFFER_LENGTH);


}

void toClient(int sock, char *buffer)
{
    int state;

    printf("\tTo Client: %s\n", buffer);

    state = write(sock, buffer, strlen(buffer));

    if (state < 0)
    {
        perror("ERROR WRITING TO SOCKET");
        exit(1);
    }
    return;
}
////