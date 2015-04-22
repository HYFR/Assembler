getOpcode: getOpcode.o
	$(CC) -o main getOpcode.o

run:
	./getOpcode

test: test.o getOpcode.o
	$(CC) -o test test.o getOpcode.o
	./test
	rm -f test

clean:
	rm -f getOpcode *.o test