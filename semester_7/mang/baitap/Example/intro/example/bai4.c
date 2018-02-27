#include	"unp.h"

int main(int argc, char const *argv[]) {
	printf("\nBai 4:\n");
	
	struct sockaddr_in antelope;  char *some_addr;  

	inet_aton("127.0.0.1", &antelope.sin_addr); // -> string

	some_addr = inet_ntoa(antelope.sin_addr); // -> binary

	printf("%s\n", some_addr); // prints "10.0.0.1"    

	antelope.sin_addr.s_addr = inet_addr("10.0.0.1"); // IPv4

///////////////
	printf("\nBai 5:\n");
	
	struct sockaddr_in temp;
	char str[INET_ADDRSTRLEN];

	inet_pton(AF_INET, "127.0.1.2", &(temp.sin_addr));  // OK

	inet_ntop(AF_INET, &(temp.sin_addr), str, INET_ADDRSTRLEN); // Return result

	printf("%s\n", str); // prints "127.0.1.2"

	exit(0);
}