#include "bsq.h"

#define ERROR_GRID "Error: Failed to create the grid.\n"

int    **create_nb_grid(char *buffer)
{
    int rows;
    int cols;
    int i;
    int **nbr_grid;


    rows = find_row_nb(buffer);
    cols =  find_col_nb(buffer);
    nbr_grid = malloc(rows * sizeof(int *));
    if (nbr_grid == NULL) {
        write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
        exit(1);
    }
    i = 0;
    while (i < rows)
    {
        nbr_grid[i] = malloc(cols * sizeof(int));
        if (nbr_grid[i] == NULL) {
            write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
            exit(1);
        }
        i++;
    }
    return (nbr_grid);
}

int    ft_swap_to_num(char *buffer, char map_grid)
{
    char    empty;
    char    obstacle;

    empty = buffer[1];
    obstacle = buffer[2];

    if (map_grid == empty)
        return (1);
    else if (map_grid == obstacle)
        return (0);
}

void    change_obst_to_zero(int ** nbr_grid, char **map_grid, char *buffer)
{
    char    obstacle;
    int i;
    int j;
    int cols;

    obstacle = buffer[2];
    i = 1;
    cols =  find_col_nb(buffer);
    while(map_grid[i][j])
    {
        j = 1;
        while (j < cols)
        {
            if (map_grid[i][j] == obstacle)
            nbr_grid[i][j] = 0;
            j++;
        }
        i++; 
    }
}

void    change_first_row(int ** nbr_grid, char **map_grid, char *buffer)
{
    int i;
    int j;
    int cols;

    i = 0;
    j = 0;
    cols =  find_col_nb(buffer);
    while (i < cols)
    {
        nbr_grid[i][j] = ft_swap_to_num(buffer, map_grid[i][j]);
        i++;
    }
}

void    change_first_col(int ** nbr_grid, char **map_grid, char *buffer)
{
    int i;
    int j;
    int rows;

    i = 0;
    j = 1;
    rows = find_row_nb(buffer);
    while (j < rows)
    {
        nbr_grid[i][j] = ft_swap_to_num(buffer, map_grid[i][j]);
        j++;
    }
}


int find_smallest(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

void    calculate_max_square(int ** nbr_grid, char **map_grid, char *buffer)
{
    int i;
    int j;
    int cols;

    i = 1;
    cols =  find_col_nb(buffer);
    change_first_col(nbr_grid, map_grid, buffer);
    change_first_row(nbr_grid, map_grid, buffer);
    change_obst_to_zero(nbr_grid, map_grid, buffer);
    while (nbr_grid)
    {
        j = 1;
        while (j < cols)
        {
            nbr_grid[i][j] = find_smallest(nbr_grid[i - 1][j], nbr_grid[i][j -1], nbr_grid[i-1][j-1]) + 1;
            j++;
        }
        i++;
    }
}



/*

CHECK BIGGEST NUMBER:

Check elements of number-grid until find the biggest number(n);
see the first time this number appear up-down, left-right. 
save the i and j. 

CHANGE THE ORIGINAL GRID:

from the element of the numbergrid:
    transform it into "full char";
    form a grid up /left (n-1 size) with full-chars 
*/