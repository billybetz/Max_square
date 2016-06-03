/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:25:13 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/15 18:04:52 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_what_type(char *piece)
{
	if ((!ft_strcmp(piece, "####\0")) || (!ft_strcmp(piece, "#\n#\n#\n#\0")))
		return (0);
	else if (!ft_strcmp(piece, "##\n##\0"))
		return (1);
	else if ((!ft_strcmp(piece, "#.\n#.\n##\0")) ||
			(!ft_strcmp(piece, "..#\n###\0"))
			|| (!ft_strcmp(piece, "##\n.#\n.#\0")) ||
			(!ft_strcmp(piece, "###\n#..\0")))
		return (2);
	else if ((!ft_strcmp(piece, ".#\n.#\n##\0")) ||
			(!ft_strcmp(piece, "###\n..#\0"))
			|| (!ft_strcmp(piece, "##\n#.\n#.\0")) ||
			(!ft_strcmp(piece, "#..\n###\0")))
		return (3);
	else if ((!ft_strcmp(piece, "#.\n##\n#.\0")) ||
			(!ft_strcmp(piece, ".#.\n###\0"))
			|| (!ft_strcmp(piece, ".#\n##\n.#\0")) ||
			(!ft_strcmp(piece, "###\n.#.\0")))
		return (4);
	else if ((!ft_strcmp(piece, "##.\n.##\0")) ||
			(!ft_strcmp(piece, ".#\n##\n#.")))
		return (5);
	else
		return (6);
}

void	ft_one_char_color(char c, char *color)
{
	ft_putstr(color);
	ft_putchar(c);
	ft_putstr(WHITE);
}

void	ft_print_color(char *str, t_tetris *p)
{
	int	i;

	i = 0;
	while (str && *str)
	{
		if (*str == '\n')
			ft_putchar('\n');
		else if ((p[*str - 65].type) == 0)
			ft_one_char_color(*str, CYAN);
		else if ((p[*str - 65].type) == 1)
			ft_one_char_color(*str, YELLOW);
		else if ((p[*str - 65].type) == 2)
			ft_one_char_color(*str, LIGHT_RED);
		else if ((p[*str - 65].type) == 3)
			ft_one_char_color(*str, LIGHT_BLUE);
		else if ((p[*str - 65].type) == 4)
			ft_one_char_color(*str, GRAY);
		else if ((p[*str - 65].type) == 5)
			ft_one_char_color(*str, LIGHT_PURPLE);
		else if ((p[*str - 65].type) == 6)
			ft_one_char_color(*str, LIGHT_GREEN);
		str++;
	}
	ft_putchar('\n');
}
