#include "board.h"
#include <stdlib.h>

Board* update_board(Board* oldBoard)
{
    
    Board *newBoard;
    newBoard = (Board *) malloc(sizeof(Board));
    newBoard->nrows = oldBoard->nrows;
    newBoard->ncols = oldBoard->ncols;
    newBoard->grid = (char *) malloc(sizeof(char)*newBoard->nrows*newBoard->ncols);
    newBoard->gridrows = (char**) malloc(sizeof(char *)*newBoard->nrows);
    int numg = 0;
    int numr = 0;
    int numneighbor = 0;
    for (int i = 0; i < newBoard->nrows; i++)
    {
	newBoard->gridrows[i] = newBoard->grid + i * newBoard->ncols;
    }

    for (int i = 0; i < newBoard->nrows; i++)
    {
	for (int j = 0; j < newBoard->ncols; j++)
	{
	    numg = 0;
	    numr = 0;
	    numneighbor = 0;
	    if ((0 < (i - 1) && (i - 1) < oldBoard->nrows) && (0 < (j - 1) && (j - 1) < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i - 1][j - 1] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i - 1][j - 1] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < (i - 1) && (i - 1)< oldBoard->nrows) && (0 < j && j < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i - 1][j] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i - 1][j] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < (i - 1) && (i - 1) < oldBoard->nrows) && (0 < (j + 1) && (j + 1) < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i - 1][j + 1] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i - 1][j + 1] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < i && i < oldBoard->nrows) && (0 < (j - 1) && (j - 1) < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i][j - 1] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i][j - 1] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < i && i < oldBoard->nrows) && (0 < (j + 1) && (j + 1) < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i][j + 1] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i][j + 1] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < (i + 1) && (i + 1) < oldBoard->nrows) && (0 < (j - 1) && (j - 1) < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i + 1][j - 1] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i + 1][j - 1] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < (i + 1) && (i + 1) < oldBoard->nrows) && (0 < j && j < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i + 1][j] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i + 1][j] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if ((0 < (i + 1) && (i + 1) < oldBoard->nrows) && (0 < (j + 1) && (j + 1) < oldBoard->ncols))
	    {
		if (oldBoard->gridrows[i + 1][j + 1] == 'r')
		{
		    numr += 1;
		    numneighbor += 1;
		}
		if (oldBoard->gridrows[i + 1][j + 1] == 'g')
		{
		    numg += 1;
		    numneighbor += 1;
		}
	    }
	    if (numneighbor > 3 || numneighbor < 2)
	    {
		newBoard->gridrows[i][j] = 'x';
	    }
	    if (oldBoard->gridrows[i][j] == 'x' && numneighbor == 3)
	    {
		if (numr > numg)
		{
		    newBoard->gridrows[i][j] = 'r';
		}
		else
		{
		    newBoard->gridrows[i][j] = 'g';
		}
	    }
	    if (1 < numneighbor && numneighbor < 4)
	    {
		newBoard->gridrows[i][j] = oldBoard->gridrows[i][j];
	    }
	}
    }
    
    free(oldBoard->gridrows);
    free(oldBoard->grid);
    free(oldBoard);
    return newBoard;
}
