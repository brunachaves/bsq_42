/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:44:01 by nleite-s          #+#    #+#             */
/*   Updated: 2024/02/21 22:44:02 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_map_valid(char *map, char *full, char *obs, char *empty)
{
	if (check_first_line(map, full, obs, empty) == 0)
	{
		if (check_char(map, full, obs, empty) == 0)
		{
			if (check_length(map) == 0)
				return (0);
		}
	}
	write(1, MAP_ERROR, sizeof(MAP_ERROR));
	return (-1);
}

int	check_first_line(char *map, char *full, char *obs, char *empty)
{
	int	i;

	i = 0;
	while ((map[i] != *obs && map[i] != *empty && map[i] != '\n'))
	{
		if (map[i] >= 32 && map[i] <= 126)
		{
			if (*obs != '\0')
				*empty = *obs;
			if (*full != '\0')
				*obs = *full;
			*full = map[i];
			i++;
		}
	}
	if (*full == *obs || *obs == *empty || *full == *empty)
	{
		write(1, MAP_ERROR, sizeof(MAP_ERROR));
		return (-1);
	}
	return (0);
}

int	calculate_head(char *map)
{
	int		i;
	char	obs;
	char	empty;
	char	full;

	obs = '\0';
	empty = '\0';
	full = '\0';
	i = 0;
	while (map[i] != obs && map[i] != empty && map[i] != '\n')
	{
		if (map[i] >= 32 && map[i] <= 126)
		{
			if (obs != '\0')
				empty = obs;
			if (full != '\0')
				obs = full;
			full = map[i];
			i++;
		}
		else
		{
			return (-1);
		}
	}
	return (i);
}

int	check_length(char *buffer)
{
	int	auxlen;
	int	i;
	int	height;

	i = calculate_head(buffer);
	height = get_height(buffer);
	auxlen = 0;
	i++;
	while (buffer[i] != '\0')
	{
		while (buffer[i] != '\0')
		{
			auxlen++;
			i++;
		}
		if (auxlen % height != 0)
		{
			write(1, MAP_ERROR, sizeof(MAP_ERROR));
			return (-1);
		}
		i++;
		auxlen = 0;
	}
	return (0);
}

int	buffer_size(char *file)
{
	int		size;
	int		fd;
	char	c;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, ERROR_OPEN, sizeof(ERROR_OPEN) - 1);
		return (-1);
	}
	while ((read(fd, &c, 1)) > 0) 
	{
		size++;
	}
	if (read(fd, &c, 1) == -1) 
	{
		write(1, ERROR_READ, sizeof(ERROR_READ) - 1);
		return (-1);
	}
	close(fd);
	return (size);
}
