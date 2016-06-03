/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:49:33 by bbetz             #+#    #+#             */
/*   Updated: 2016/03/24 16:26:43 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_file(char *av, char ***map)
{
	int		fd;
	int		nb_return;
	int		i;
	char	*line;

	i = 0;
	nb_return = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		nb_return++;
	}
	close(fd);
	if (!(*map = (char**)malloc(sizeof(char*) * (nb_return + 1))))
		return ;
	if ((fd = open(av, O_RDONLY)) < 0)
		return ;
	while (get_next_line(fd, &((*map)[i])) > 0)
		i++;
	close(fd);
	(*map)[i] = NULL;
}
