all : conway.c board.c board.h
    gcc -o conway.o conway.c board.c board.h

clear : conway.o
    rm conway.o
