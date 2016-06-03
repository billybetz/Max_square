/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 22:54:18 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/17 11:04:13 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_rc_test(char *s)
{
	int i;
	int c;

	if (s)
	{
		if (ft_strlen(s) == 20)
			return ((POS_OF_10) ? 1 : 0);
		i = 4;
		c = 0;
		while (s[i])
		{
			if (s[i] != '\n')
				return (0);
			i += (c == 3) ? 6 : 5;
			c += (c == 4) ? 0 : 1;
			if (c == 4)
			{
				c = 0;
				if (s[i] == '\0')
					return (1);
			}
		}
	}
	return (0);
}

int				ft_co2(char *map, int nb_connexions, int y, int i)
{
	{
		if (map[i + 1] == '#')
			nb_connexions++;
		if (i + 5 < (y * 21) && map[i + 5] == '#')
			nb_connexions++;
	}
	return (nb_connexions);
}

static	int		ft_co(char *map, int i)
{
	int			nb_connexions;
	static int	y = 0;

	y++;
	nb_connexions = 0;
	if (i == 2)
		i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n' && (map[i + 1] == '\n' || map[i + 1] == '\0'))
		{
			if (nb_connexions >= 3)
				return (1);
			else
				return (0);
		}
		if (map[i] == '#')
			nb_connexions = ft_co2(map, nb_connexions, y, i);
		i++;
	}
	if (nb_connexions >= 3)
		return (1);
	return (0);
}

int				ft_check_tetr2(t_check_t *i, char *map)
{
	if (i->i == 0 || (map[i->i] == '\n' && map[i->i + 1] == '\n'))
	{
		if (ft_co(map, i->i + 2) == 0)
			return (0);
	}
	if (map[i->i] != '.' && map[i->i] != '#' && map[i->i] != '\n')
		return (0);
	if (map[i->i] == '.')
		i->nb_dot++;
	if (map[i->i] == '#')
		i->nb_dieze++;
	if (i->nb_dot > 12 || i->nb_dieze > 4)
		return (0);
	return (1);
}

int				ft_check_tetriminos(char *map, int *nb_tetriminos)
{
	t_check_t	i;

	i.i = -1;
	i.nb_tetriminos = 0;
	i.nb_dieze = 0;
	i.nb_dot = 0;
	if (ft_rc_test(map) == 0)
		return (0);
	while (map && map[++i.i])
	{
		if (ft_check_tetr2(&i, map) == 0)
			return (0);
		if (map[i.i] == '\n' && (map[i.i + 1] == '\n' || map[i.i + 1] == '\0'))
		{
			if (NB_DO != 12 || NB_DI != 4 || map[i.i - 1] == '\n' || NB_T > 26)
				return (0);
			i.nb_dieze = 0;
			i.nb_dot = 0;
			i.nb_tetriminos++;
		}
	}
	if ((i.nb_tetriminos) < 1)
		return (0);
	*nb_tetriminos = i.nb_tetriminos;
	return (1);
}
