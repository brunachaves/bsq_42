#include "bsq.h"

int main(int argc, char **argv)
{
    int fd;
    int  bytes_read;
    char    buffer[1024];

    if (argc == 1)
        //read on stand input
    else (argc > 1)
    {
        fd = open("map.txt", O_RDONLY);
        if (fd == -1)
        {
            //ERROR
            exit(1);
        }
    }
    bytes_read = read(fd, buffer, 1023)
    if (bytes_read == -1) 
    {
        //ERROR
        close(fd);
        exit(1); 
    }
    buffer[bytes_read] = '\0';

/*
    check if map is valid; (map_is_valid.c)
    
    create a grid: (creat_grid.c)

    calculate / manipulate grid; (calculate.c)

    transform grid with "full char" square. (calculate.c)

    print it;

    close(fd);
    */
}