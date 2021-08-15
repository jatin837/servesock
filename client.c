#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
	// The Socket Discriptor
	int net_sock;
	//Creating Socket
	net_sock = socket(AF_INET, SOCK_STREAM, 0);

	// Specify an address, and port for the socket
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(9002);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	int conn_status = connect(
				net_sock,
				(struct sockaddr *) &serv_addr,
				sizeof(serv_addr)
			);

	if (!conn_status)
		printf("ERROR WHILE CONNECTING\n");

	char serv_res[256];

	recv(
				net_sock,
				&serv_res,
				sizeof(serv_res),
				0
			);

	// print out the server's response
	printf("The server sent the data:  %s\n", serv_res);
	
	// close the socket connection
	close(net_sock);

	return 0;
}
