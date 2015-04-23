CC=gcc
CFLAGS :=  $(CFLAGS) -Wall -g -Werror

Lab1: Lab1.o main.o
	$(CC) $(CFLAGS) Lab1.o main.o -lm -o Lab1

test: Lab1.o test.o
	$(CC) $(CFLAGS) Lab1.o test.o -lm -o test
	./test

run: Lab1
	./Lab1

clean:
	rm -f Lab1 test *.o