#include "bsq.h"

int main(int argc, char **argv)
{
	int fd;
	int  size;
	int bytes_read;
	char    *buffer;

	if (argc == 1)
	{
		//read on stand input usando read(0, ..., ...)
		bytes_read = read(0, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			write(1, "Something's wrong with the input", 32);
		}
	}
	else if (argc > 1)
	/*
	a gente tem que ser capaz de ler se colocarem 10293 mapas diferentes
	talvez setar um counter e declarar assim:*/
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
	
	//Desse modo a gente le um e atualiza o counter pra ler o outro. 
	/*
	VAMOS LER AGORA
	No inicio de map.pl, a primeira coisa eh o tamanho da linha. Entao a gente pode ler essa info pra determinar tamanho de buffer
	*/
		char c; //a ideia eh ler o mapa letter by letter ja que eh so esses digitos iniciais
		int len;

		len = 0;
		c = ' ';
		while (read(fd, &c, 1) == 1 c != '.') //ex "20.ox"
		{
		   if (c >= '0' && c <= '9') 
				len = (len * 10) + (c - '0');
		}
   /*
	check if map is valid; (map_is_valid.c)
	
	creat a grid: (creat_grid.c)

	calculate / manipulate grid; (calculate.c)

	transform grid with "full char" square. (calculate.c)

	print it;
	*/
	close(fd);
	}
}