/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:23:46 by nleite-s          #+#    #+#             */
/*   Updated: 2024/02/21 22:23:47 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define ERROR_OPEN "Error: Could not open the file.\n"
#define ERROR_READ "Error: Could not read the file.\n"

int	main(int argc, char **argv)
{
	int		i;
	int		bytes_read;
	char	*buffer;
	char	empty;

	if (argc == 1)
	{
		write(1, "Enter your input (Press Enter to finish):\n", 43);
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		buffer[bytes_read] = '\0';
		parse_map(buffer, &empty);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			read_open(argv[i], &buffer);
			parse_map(buffer, &empty);
			free(buffer);
			i++;
		}
	}
	return (0);
}

int	read_open(char *filename, char **buffer)
{
	int	fd;
	int	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, ERROR_OPEN, sizeof(ERROR_OPEN) - 1);
		return (-1);
	}
	*buffer = malloc(buffer_size(filename) * sizeof(char));
	bytes_read = read(fd, *buffer, 1023);
	if (bytes_read == -1)
	{
		write(1, ERROR_READ, sizeof(ERROR_READ) - 1);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	parse_map(char *buffer, char *empty)
{
	char	**map_grid;
	int		**nbr_grid;
	int		*max_i_j;
	char	obs;
	char	full;

	*empty = '\0';
	obs = '\0';
	full = '\0';
	is_map_valid(buffer, &full, &obs, empty);
	map_grid = create_grid(buffer);
	populate_grid(buffer, map_grid);
	nbr_grid = create_nb_grid(buffer);
	calculate_max_square(nbr_grid, map_grid, buffer);
	max_i_j = check_biggest_nbr(nbr_grid, buffer);
	change_map(map_grid, max_i_j, buffer);
	print_matrix(map_grid, buffer);
	return (0);
}
