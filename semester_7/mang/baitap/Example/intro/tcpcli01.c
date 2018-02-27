#include "unp.h"

#ifndef MAXLINE
#define MAXLINE 256
#endif

#ifndef SERV_PORT
#define SERV_PORT 8888
#endif

void str_cli(FILE *fp, int sockfd);

int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc != 2) {
		err_quit("usage: tcpcli <IPaddress>");
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	printf("\nConnected to port: %d\n", servaddr.sin_port);

	str_cli(stdin, sockfd);

	exit(0);
}


void str_cli(FILE *fp, int sockfd) {
	char sendline[MAXLINE+1], recvline[MAXLINE+1];

	while(fgets(sendline, MAXLINE, fp) != NULL) {
		writen(sockfd, sendline, strlen(sendline));

		if(readline(sockfd, recvline, MAXLINE) == 0) {
			err_quit("str_cli: server terminated prematurely");
		}

		fputs(recvline, stdout);
	}
};