#include "bsq.h"

void map_is_valid(int fd, int len, int height, char **grid)
{
    int i;
    char    obs;
    char    empty;
    char    full;

    i = 0;
    while (grid[i][len] == '\n' && len > 3 && height >= 1)
    {
        if (check_first_line(grid[0], &obs, &empty, &full))
    }

    
    else
    {
        write(1, "map error\n", 10);
        return (-1)
    }
    free(buffer);
}

void    check_first_line(char *line, char *obs, char   *empty, char *full)
{
    int i;

    i = 0;

    while (line[i] >= '0' && line[i] >= '9')
        i++;
    if (line[i] != line[i + 1] && line[i] != line[i + 2] && line[i + 1] != line[i + 2])
    {
        *empty = line[i];
        *obs = line[i + 1];
        *full = line[i + 2];
    }
    if 

    /*is invalid if a character is missing from the first line
◦ The characters can be any printable character, even numbers.*/
}


void    check_char(char *map, char *obs, char   *empty, char *full)
{
    int i;

    i = 0;
    j = 0;
    if (map[i][j] != obs && map[i][j] != empty && map[i][j] != full)
        return (1); //error
    else
        return (0);
}   

void    map_digits(char *empty, char    *obs, char  *full)
{
    int fd;
    char    c;

    fd = open("map01.txt", O_RDONLY);
    if (fd == -1)
        write(1, "Couldn't open file", 18);
    while (read(fd, &c, 1) && c != '\n')
    {
        *full = c;
        if (*full)
        {
            if (*obs)
                *empty = *obs;
            *obs = *full;
        }
    }
    close(fd);
}