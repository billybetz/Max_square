/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 16:47:44 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/17 11:04:59 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_endmap(char *map, t_tetris *p, int y[2], int *i)
{
	if (y[0] == 0)
	{
		y[1]++;
		ft_new_map(y[1], map, p);
		*i = 0;
	}
	else if (y[0] >= 1)
	{
		y[0]--;
		ft_delete_piece(map, p[y[0]].name);
		*i = p[y[0]].position + 1;
	}
}
