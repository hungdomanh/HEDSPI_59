#include	"unp.h"

int main(int argc, char const *argv[]) {
	struct sockaddr_in temp;
	char str[INET_ADDRSTRLEN];

	inet_pton(AF_INET, "127.0.1.2", &(temp.sin_addr));  // OK

	inet_ntop(AF_INET, &(temp.sin_addr), str, INET_ADDRSTRLEN); // Return result

	printf("%s\n", str); // prints "127.0.1.2"

	exit(0);
}