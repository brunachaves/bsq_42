/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleite-s <nleite-s@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:44:41 by nleite-s          #+#    #+#             */
/*   Updated: 2024/02/21 22:44:43 by nleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_row_nb(char *buffer)
{
	int	row;

	row = 0;
	while (*buffer != '\n')
		buffer++;
	buffer++;
	while (*buffer)
	{
		while (*buffer && *buffer != '\n')
		{
			buffer++;
		}
		row++;
		buffer++;
	}
	return (row);
}

int	find_col_nb(char *buffer)
{
	int	col;

	col = 0;
	while (*buffer != '\n')
		buffer++;
	buffer++;
	while (*buffer && *buffer != '\n')
	{
		col++;
		buffer++;
	}
	return (col);
}

int	find_smallest(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}
