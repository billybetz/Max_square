/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:37:53 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/17 11:04:22 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_positions(t_tetris *pp)
{
	int i;

	i = 0;
	while (pp[i].position != -1)
	{
		pp[i].position = -1;
		i++;
	}
}

void		ft_init_piece2(t_tetris *p, int pos[5], int i)
{
	if (pos[2] != -1)
		pos[3] = i;
	else if (pos[1] != -1)
		pos[2] = i;
	else if (pos[0] != -1)
		pos[1] = i;
	else if (pos[0] == -1)
		pos[0] = i;
	if (pos[3] != -1)
	{
		p[pos[4]].piece = ft_put_piece1(pos);
		p[pos[4]].size_x = ft_put_size_x1(pos);
		p[pos[4]].size_y = ft_put_size_y1(pos);
		p[pos[4]].position = -1;
		p[pos[4]].name = 65 + pos[4];
		p[pos[4]].type = ft_what_type(p[pos[4]].piece);
		pos[4]++;
	}
}

void		ft_init_piece(char *input, t_tetris *p)
{
	int pos[5];
	int i;

	i = 0;
	pos[0] = -1;
	pos[1] = -1;
	pos[2] = -1;
	pos[3] = -1;
	pos[4] = 0;
	while (input[i])
	{
		if (input[i] == '\n' && input[i + 1] == '\n')
		{
			pos[0] = -1;
			pos[1] = -1;
			pos[2] = -1;
			pos[3] = -1;
			i += 2;
		}
		if (input[i] == '#')
			ft_init_piece2(p, pos, i);
		i++;
	}
}

void		ft_init_tetris(int nb_tetriminos, char *input, t_tetris *p)
{
	int i;

	i = 0;
	ft_init_piece(input, p);
	p[nb_tetriminos].piece = NULL;
}
