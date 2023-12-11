#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(void){
    Board *conway;
    conway = (Board *) malloc(sizeof(Board));
    int row = 0;
    int col = 0;
    scanf("%d %d", &row, &col);
    conway->nrows = row;
    conway->ncols = col;
    conway->grid = (char *) malloc(sizeof(char)*conway->nrows*conway->ncols);
    conway->gridrows = (char**) malloc(sizeof(char *)*conway->nrows);
    int numiterations = 0;

    for (int i = 0; i < conway->nrows; i++)
    {
	conway->gridrows[i] = conway->grid + i * conway->ncols;
    }

    scanf("%d", &numiterations);

    for (int i = 0; i < conway->nrows; i++)
    {
	char *temp = (char *) malloc(sizeof(char)*conway->ncols*2+1);
	temp = fgets(temp, conway->ncols * 2, stdin);
	for (int j = 0; j < conway->ncols * 2; j += 2)
	{
	    conway->gridrows[i][j/2] = temp[j];
	}
	free(temp);
    }

    for (int i = 0; i < numiterations; i++)
    {
	conway = update_board(conway);
    }

    int numg = 0;
    int numr = 0;

    for (int i = 0; i < conway->nrows; i++)
    {
	for (int j = 0; j < conway->ncols; j++)
	{
	    if (conway->gridrows[i][j] == 'r')
	    {
		numr += 1;
	    }
	    if (conway->gridrows[i][j] == 'g')
	    {
		numg += 1;
	    }
	}
    }

    printf("green: %d, red: %d\n", numg, numr);
    
    free(conway->gridrows);
    free(conway->grid);
    free(conway);
    
    return 0;
}
