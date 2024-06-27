/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:59:13 by brchaves          #+#    #+#             */
/*   Updated: 2024/02/21 19:37:29 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define ERROR_GRID "Error: Failed to create the grid.\n"
#define ERROR_MALLOC "Memory allocation failed\n"

int	**create_nb_grid(char *buffer)
{
	int	rows;
	int	cols;
	int	i;
	int	**nbr_grid;

	rows = find_row_nb(buffer);
	cols = find_col_nb(buffer);
	nbr_grid = malloc(rows * sizeof(int *));
	if (nbr_grid == NULL)
	{
		write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		nbr_grid[i] = malloc(cols * sizeof(int));
		if (nbr_grid[i] == NULL)
		{
			write(1, ERROR_GRID, sizeof(ERROR_GRID) - 1);
			exit(1);
		}
		i++;
	}
	return (nbr_grid);
}

void	ft_swap_to_num(char **map_grid, int **nbr_grid, char *buffer)
{
	char	obstacle;
	int		i;
	int		j;
	int		cols;
	int		rows;

	obstacle = buffer[2];
	i = 0;
	cols = find_col_nb(buffer);
	rows = find_row_nb(buffer);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map_grid[i][j] == obstacle)
				nbr_grid[i][j] = 0;
			else
				nbr_grid[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	calculate_max_square(int **n_g, char **map_grid, char *buffer)
{
	int	i;
	int	j;
	int	cols;
	int	rows;

	i = 1;
	cols = find_col_nb(buffer);
	rows = find_row_nb(buffer);
	ft_swap_to_num(map_grid, n_g, buffer);
	while (i < rows)
	{
		j = 1;
		while (j < cols)
		{
			if (n_g[i][j] != 0)
			{
				n_g[i][j] = find_smallest(n_g[i - 1][j], n_g[i][j - 1], n_g[i - 1][j - 1]) + 1;
			}
			j++;
		}
		i++;
	}
}

int	*check_biggest_nbr(int **nbr_grid, char *buffer)
{
	int	i;
	int	j;
	int	max;
	int	cols;
	int	rows;
	int	saved_i;
	int	saved_j;
	int	*max_i_j;

	i = 0;
	cols = find_col_nb(buffer);
	rows = find_row_nb(buffer);
	max = 1;
	max_i_j = (int *)malloc(3 * sizeof(int));
	if (max_i_j == NULL)
	{
		write(1, ERROR_MALLOC, sizeof(ERROR_MALLOC));
		exit(1);
	}
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (nbr_grid[i][j] > max)
			{
				max = nbr_grid[i][j];
				saved_i = i;
				saved_j = j;
			}
			j++;
		}
		i++;
	}
	max_i_j[0] = max;
	max_i_j[1] = saved_i;
	max_i_j[2] = saved_j;
	return (max_i_j);
}

void	change_map(char **map_grid, int *max_i_j, char *buffer)
{
	int		i;
	int		j;
	int		lim_i;
	int		lim_j;
	char	full;

	i = max_i_j[1];
	lim_i = i - max_i_j[0] + 1;
	j = max_i_j[2];
	lim_j = j - max_i_j[0] + 1;
	full = buffer[3];
	while (i >= lim_i)
	{
		j = max_i_j[2];
		while (j >= lim_j)
		{
			map_grid[i][j] = full;
			j--;
		}
		i--;
	}
}
