all : conway.o board.o
	gcc -Wall -o conway.out conway.o board.o

board.o : board.c board.h
	gcc -c board.c board.h

conway.o : conway.c board.h
	gcc -c conway.c board.h

clean:
	rm conway.o board.o conway.out
