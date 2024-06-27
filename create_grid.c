/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:24:13 by brchaves          #+#    #+#             */
/*   Updated: 2024/02/21 19:09:17 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define ERROR_GRID "Error: Failed to create the grid.\n"

void	error_show(void)
{
	write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
	exit(1);
}

char	**create_grid(char *buffer)
{
	int		x;
	int		y;
	int		i;
	char	**grid;

	y = buffer[0] - 48;
	x = 0;
	while (*buffer != '\n')
	{
		x++;
		buffer++;
	}
	grid = malloc(y * sizeof(char *));
	if (grid == NULL)
		error_show();
	i = 0;
	while (i < y)
	{
		grid[i] = malloc(x * sizeof(char));
		if (grid[i] == NULL)
			error_show();
		i++;
	}
	return (grid);
}

void	free_grid(char **grid, int y)
{
	int	i;

	i = 0;
	while (i < y) 
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	populate_grid(char *buffer, char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (*buffer != '\n')
		buffer++;
	buffer++; 
	while (*buffer)
	{
		j = 0;
		while (*buffer != '\n')
		{
			grid[i][j] = *buffer;
			j++;
			buffer++;
		}
		i++;
		buffer++;
	}
}

void	print_matrix(char **matrix, char *buffer)
{
	int		rows;
	int		cols;
	int		i;
	int		j;
	char	nl;

	rows = find_row_nb(buffer);
	cols = find_col_nb(buffer);
	i = 0;
	nl = '\n';
	while (i < rows)
	{
		j = 0; 
		while (j < cols)
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, &nl, 1);
		i++;
	}
}
