/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:39:29 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/17 11:04:52 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_new_map(int size_map, char *map, t_tetris *p)
{
	int		i;
	int		x;

	x = 1;
	i = 0;
	while (x < size_map)
	{
		while (i < (size_map * x - 1))
		{
			map[i] = '.';
			i++;
		}
		map[i] = '\n';
		i++;
		x++;
	}
	map[i - 1] = '\0';
	ft_init_positions(p);
}

void	ft_delete_piece(char *map, char c)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == c)
			map[i] = '.';
		i++;
	}
}

int		ft_check_place(char *map, char *piece, int i, int size_map)
{
	int	z;
	int nb_ret;
	int	pos_x;

	nb_ret = 0;
	z = 0;
	pos_x = 0;
	while (piece[z] != '\0')
	{
		if (piece[z] == '#' && (map[i + pos_x + (size_map * nb_ret)] != '.'))
			return (0);
		pos_x++;
		if (piece[z] == '\n')
		{
			pos_x = 0;
			nb_ret++;
		}
		z++;
	}
	return (1);
}

void	ft_place_piece(char *map, t_tetris pp, int i, int size_map)
{
	int	z;
	int nb_ret;
	int	pos_x;
	int pos;

	pos = 0;
	nb_ret = 0;
	z = 0;
	pos_x = 0;
	while (pp.piece[z] != '\0')
	{
		if (pp.piece[z] == '#' && map[i + pos_x + (size_map * nb_ret)] == '.')
		{
			map[i + pos_x + (size_map * nb_ret)] = pp.name;
			pos++;
		}
		pos_x++;
		if (pp.piece[z] == '\n')
		{
			pos_x = 0;
			nb_ret++;
		}
		z++;
	}
}

char	*ft_solve(char *map, t_tetris *p)
{
	int		i;
	int		y[2];

	y[1] = 3;
	y[0] = 0;
	i = 0;
	while (p[y[0]].piece != NULL)
	{
		if ((ft_check_place(map, p[y[0]].piece, i, y[1])) == 1)
		{
			p[y[0]].position = i;
			ft_place_piece(map, p[y[0]], i, y[1]);
			i = 0;
			y[0]++;
		}
		else
			i++;
		if (map[i] == '\0')
			ft_endmap(map, p, y, &i);
	}
	return (map);
}
