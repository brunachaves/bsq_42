/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:28:06 by nleite-s          #+#    #+#             */
/*   Updated: 2024/02/21 22:28:08 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_height(char *buffer)
{
	int	i;
	int	height;
	int	count;

	i = calculate_head(buffer) - 3;
	height = 0;
	count = 0;
	while (i >= 0 && buffer[count] >= '0' && buffer[count] <= '9')
	{
		height = height * 10 + (buffer[count] - '0');
		i--;
		count ++;
	}
	return (height);
}

int	check_char(char *m, char *full, char *obs, char *empty)
{
	int	i;

	i = calculate_head(m);
	while (m[i] != '\n')
	{
		if (m[i] == *full || m[i] == *obs || m[i] == *empty || m[i] != '\n')
		{
			i++;
		}
		else
		{
			write(1, MAP_ERROR, sizeof(MAP_ERROR));
			return (-1);
		}
	}
	return (0);
}
