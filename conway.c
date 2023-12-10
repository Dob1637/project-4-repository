#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

int main(void){
    Board *conway;
    conway = (Board *) malloc(sizeof(Board));
    scanf("%d %d", &(conway->nrows), &(conway->ncols));
    conway->grid = (char *) malloc(sizeof(char)*conway->nrows*conway->ncols);
    conway->gridrows = (char**) malloc(sizeof(char)*conway->nrows);
    int numiterations = 0;

    for (int i = 0; i < conway->nrows; i++)
    {
	conway->gridrows[i] = conway->grid + i * ncols;
    }

    for (int i = 0; i < conway->rows; i++)
    {
	char *temp = (char *) malloc(sizeof(char)*ncol*2);
	temp = fgets(temp, conway->ncols * 2, stdin);
	for (int j = 0; j < conway->ncols * 2; j + 2)
	{
	    conway->gridrows[i][j/2] = temp[j];
	}
	free(temp);
    }

    scanf("%d", &numiterations)

    for (int i = 0; i < numiterations; i++)
    {
	conway = update_board(conway);
    }

    int numg = 0;
    int numr = 0;

    for (int i = 0; i < conway->nrows; i++)
    {
	for (int j = 0; j < conway->ncols; j++);
	{
	    if conway->gridrows[i][j] == 'r'
	    {
		numr += 1;
	    }
	    if conway->gridrows[i][j] == 'g'
	    {
		numg += 1;
	    }
	}
    }

    printf("green: %d, red: %d\n", numg, numr);
    
    return 0;
}
