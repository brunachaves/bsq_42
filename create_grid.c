#include "bsq.h"

#define ERROR_GRID "Error: Failed to create the grid.\n"

char    **create_grid(char *buffer)
{
    int x;
    int y;
    int i;
    char    **grid;

     y = buffer[0] - 48;
     x = 0;
     while(*buffer != '\n')
     {
        x++;
        buffer++;
     }
        
    
    grid = malloc(y * sizeof(char *));
    if (grid == NULL) {
        write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
        exit(1);
    }
    i = 0;
    while (i < y)
    {
        grid[i] = malloc(x * sizeof(char));
        if (grid[i] == NULL) {
            write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
            exit(1);
        }
        i++;
    }
    return (grid);
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

void    populateGrid(char *buffer, char **grid) 
{
    int i;
    int j;

    i = 0;
    buffer += 4;
    while(*buffer)
    {
        j = 0;
        while(*buffer != '\n')
        {
            grid[i][j] = *buffer;
            j++;
            buffer++;
        }
        i++;
        buffer++;
    } 
}

void    printGrid(char **grid, int x, int y) {
    int i;
    int j;
    char new_line;

    i = 0;
    new_line = '\n';
    while (i < y)
    {
        j = 0;
        while (j < x) 
        {
            write(1, grid[i][j], 1);
            j++;
        }
        write(1, &new_line, 1);
        i++;
    }
}