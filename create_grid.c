#include "bsq.h"

char    **create_grid(char *buffer)
{
    int x;
    int y;
    int i;
    char    **grid;

     y = buffer[0];
     x = 0;
     while(*buffer != '\n')
        x++;
    
    grid = malloc(y * sizeof(char *));
    if (grid == NULL) {
       //ERROR
        exit(1);
    }
    while (i < y)
    {
        grid[i] = malloc(x * sizeof(char));
        if (grid[i] == NULL) {
            //ERROR
            exit(1);
        }
        i++;
    }
    return grid;
}

void    freeGrid(char **grid, int y) {
    int i;

    i = 0;
    while (i < y) 
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

void    populateGrid() 
{
    
}


void    printGrid(char **grid, int x, int y) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}




    /*
     grid[i][j]: 
        i - (first item of maps first line -1) [atoi]
        j - (count until reaches '\n' - 1) [strlen];  
    */


