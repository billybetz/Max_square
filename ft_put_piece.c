/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:38:48 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/17 11:04:34 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_put_piece2(int p[5])
{
	if ((p[1] == p[0] + 1) && (p[2] == p[1] + 4) && (p[3] == p[2] + 1))
		return ("##\n##\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 4))
		return ("###\n.#.\0");
	else if ((p[1] == p[0] + 4) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return (".#.\n###\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 1) && (p[3] == p[2] + 4))
		return ("#.\n##\n#.\0");
	else if ((p[1] == p[0] + 4) && (p[2] == p[1] + 1) && (p[3] == p[2] + 5))
		return (".#\n##\n.#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 3) && (p[3] == p[2] + 1))
		return (".##\n##.\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 5) && (p[3] == p[2] + 1))
		return ("##.\n.##\0");
	else if ((p[1] == p[0] + 4) && (p[2] == p[1] + 1) && (p[3] == p[2] + 4))
		return (".#\n##\n#.\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 1) && (p[3] == p[2] + 5))
		return ("#.\n##\n.#\0");
	return (NULL);
}

char	*ft_put_piece1(int p[5])
{
	if (p[1] == (p[0] + 1) && p[2] == (p[1] + 4) && p[3] == p[2] + 5)
		return ("##\n#.\n#.\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 5) && (p[3] == p[2] + 5))
		return ("##\n.#\n.#\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return ("#..\n###\0");
	else if ((p[1] == p[0] + 3) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return ("..#\n###\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 5))
		return ("###\n..#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 3))
		return ("###\n#..\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 4) && (p[3] == p[2] + 1))
		return (".#\n.#\n##\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 5) && (p[3] == p[2] + 1))
		return ("#.\n#.\n##\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 5) && (p[3] == p[2] + 5))
		return ("#\n#\n#\n#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return ("####\0");
	else
		return (ft_put_piece2(p));
}
