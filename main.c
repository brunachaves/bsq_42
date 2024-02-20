#include "bsq.h"

int main(int argc, char **argv)
{
	int fd;
	int  size;
	int bytes_read;
	char    *buffer;

	if (argc == 1)
	{
		bytes_read = read(0, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			write(1, "Something's wrong with the input", 32);
		}
	}
	else if (argc > 1)
	{
		int i;
		int fd;

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
	
		char c;
		int len;
		int	height;
		char *buffer = malloc(height * len * (sizeof(char));
		
		height = 0;
		len = 0;
		c = ' ';
		while (read(fd, &c, 1) == 1 && c != '\n')
		{
		   while (c >= '0' && c <= '9')
		   {
				height = height * 10 + (c - '0');
		   }
		   len ++;
		}
	    //is_map_valid()
		
		while (read(fd, &buffer, sizeof(buffer)) != EOF)
			

		
   /*
	check if map is valid; (map_is_valid.c)
	
	creat a grid: (creat_grid.c)

	calculate / manipulate grid; (calculate.c)

	transform grid with "full char" square. (calculate.c)

	print it;
	*/
	write(1, "\n", 1);
	close(fd);
	}
}