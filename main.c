/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:24:26 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/18 14:39:37 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	remplacer "ft_putendl(map)" par "ft_print_color(map, p)"
**	dans la fonction main pour les tetriminos en couleur.
*/

int				ft_sizeof_file(char *av)
{
	int		size;
	int		fd;
	char	buf;

	size = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buf, 1))
		size++;
	return (size);
}

char			*ft_recup_input(int fd, char *av)
{
	char	*input;
	int		file_len;

	file_len = ft_sizeof_file(av);
	input = ft_strnew(file_len);
	while (read(fd, input, file_len))
		;
	input[file_len] = '\0';
	return (input);
}

static void		ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

int				main(int ac, char **av)
{
	int			fd;
	char		*input;
	char		*map;
	int			nb_tetriminos;
	t_tetris	*p;

	p = NULL;
	input = NULL;
	map = (char*)malloc(sizeof(char) * 800);
	if (ac != 2)
		ft_error();
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error();
	input = ft_recup_input(fd, av[1]);
	close(fd);
	if (ft_check_tetriminos(input, &nb_tetriminos) == 0)
		ft_error();
	p = (t_tetris*)malloc(sizeof(t_tetris) * nb_tetriminos + 1);
	ft_init_tetris(nb_tetriminos, input, p);
	ft_new_map(3, map, p);
	map = ft_solve(map, p);
	ft_putendl(map);
	return (0);
}
