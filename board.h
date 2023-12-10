#ifndef BOARD_H
#define BOARD_H

typedef struct Board{
    char *grid;
    char **gridrows;
    int nrows;
    int ncols;
}

Board* update_board(Board* oldBoard);

#endif
