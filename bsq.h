#ifndef BSQ_H
# define BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char    **create_grid(char *buffer);
void    freeGrid(char **grid, int y);
void    populateGrid(char *buffer, char **grid);
void printMatrix(char **matrix, char *buffer) ;

#endif