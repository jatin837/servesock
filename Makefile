all: client.o server.o
	clang -o cli client.o
	clang -o serv server.o

client.o: client.c
	clang -c -o client.o client.c

server.o: server.c
	clang -c -o server.o server.c

clean:
	rm *.o cli serv
