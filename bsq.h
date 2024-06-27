/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:18:35 by nleite-s          #+#    #+#             */
/*   Updated: 2024/02/21 22:18:36 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define MAP_ERROR "map error\n"
# define ERROR_OPEN "Error: Could not open the file.\n"
# define ERROR_READ "Error: Could not read the file.\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	**create_grid(char *buffer);
void	free_grid(char **grid, int y);
void	populate_grid(char *buffer, char **grid);
void	print_matrix(char **matrix, char *buffer);
int		**create_nb_grid(char *buffer);
void	ft_swap_to_num(char **map_grid, int **nbr_grid, char *buffer);
void	change_obst_to_zero(int **nbr_grid, char **map_grid, char *buffer);
void	change_first_row(int **nbr_grid, char **map_grid, char *buffer);
void	change_first_col(int **nbr_grid, char **map_grid, char *buffer);
int		find_smallest(int a, int b, int c);
void	calculate_max_square(int **nbr_grid, char **map_grid, char *buffer);
int		*check_biggest_nbr(int **nbr_grid, char *buffer);
void	change_map(char **map_grid, int *max_i_j, char *buffer);
int		find_row_nb(char *buffer);
int		find_col_nb(char *buffer);
void	print_nbr_grid(int **nbr_grid, char *buffer);
int		is_map_valid(char *map, char *full, char *obs, char *empty);
int		check_first_line(char *map, char *full, char *obs, char *empty);
int		check_length(char *buffer);
int		check_char(char *m, char *full, char *obs, char *empty);
int		buffer_size(char *file);
int		parse_map(char *buffer, char *empty);
int		read_open(char *file, char **buffer);
int		get_height(char *buffer);
int		calculate_head(char *map);

#endif
