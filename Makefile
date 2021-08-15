all: main.o
	clang -o exe main.o

main.o: main.c
	clang -c -o main.o main.c

clean:
	rm *.o exe
