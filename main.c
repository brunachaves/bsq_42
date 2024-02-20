#include "bsq.h"


int main(int argc, char **argv)
{
    int fd;
    int i;
    int  bytes_read;
    char    buffer[1024];
    char    **map_grid;

    if (argc == 1)
    {
        bytes_read = read(STDIN_FILENO, buffer, 1023);
    }
    i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			return ("Error!\n");
		}
		i ++;
	}
    bytes_read = read(fd, buffer, 1023);
    if (bytes_read == -1) 
    {
        char error_read[] = "Error: Failed while trying to read the map file.\n";
        write(1, &error_read, 42);
        close(fd);
        exit(1); 
    }
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);

    map_grid = create_grid(buffer);


    populateGrid(buffer, map_grid);

    printMatrix(map_grid, buffer);
     /*
    check if map is valid; (map_is_valid.c)
    
    create a grid: (creat_grid.c)

    calculate / manipulate grid; (calculate.c)

    transform grid with "full char" square. (calculate.c)

    print it;

    freegrid
*/
    close(fd);
    return (0);
}