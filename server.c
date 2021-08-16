#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
	
	char serv_msg[256] = "You contacted The server?";
	int net_sock;
	//Creating Socket
	net_sock = socket(AF_INET, SOCK_STREAM, 0);

	// Specify an address, and port for the socket
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(9002);
	serv_addr.sin_addr.s_addr = INADDR_ANY;


	bind(
				net_sock,
				(struct sockaddr *) &serv_addr,
				sizeof(serv_addr)
		);

	listen(
			net_sock,
			5
		);

	while(1){
		int client_sock;
		client_sock = accept(net_sock, NULL, NULL);

		if (client_sock < 0)
			printf("connected");

		send(client_sock, serv_msg, sizeof(serv_msg), 0);
	}
	
	// close the socket connection
	close(net_sock);

	return 0;
}
