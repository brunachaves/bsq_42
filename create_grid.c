#include "bsq.h"

#define ERROR_GRID "Error: Failed to create the grid.\n"

int find_row_nb(char*buffer)
{
    int row;

    row = 0;
    while (*buffer != '\n')
        buffer++;
    buffer++;
    while (*buffer)
    {
        while (*buffer && *buffer != '\n')
        {
            buffer++;
        }
        row++;
        buffer++;
    }
    return (row);
}

int find_col_nb(char*buffer)
{
    int col;

    col = 0;
    while (*buffer != '\n')
        buffer++;
    buffer++;
    while (*buffer && *buffer != '\n')
    {
        col++;
        buffer++;
    }
    return (col);
}

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

void    freeGrid(char **grid, int y)
{
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
    while(*buffer != '\n')
        buffer++;
    buffer++; 
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

void printMatrix(char **matrix, char *buffer) 
{
    int rows; 
    int cols; 
    int i;
    int j;

    rows = find_row_nb(buffer);
    cols =  find_col_nb(buffer);
    i = 0;
    while (i < rows) {
        j = 0; 
        while (j < cols) {
            printf("%c", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}