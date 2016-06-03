/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:41:14 by bbetz             #+#    #+#             */
/*   Updated: 2016/04/17 11:05:12 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define POS_OF_10 "s[4] == 10 && s[9] == 10 && s[14] == 10 && s[19] == 10"
# define NB_T i.nb_tetriminos
# define NB_DI i.nb_dieze
# define NB_DO i.nb_dot

typedef struct		s_check_t
{
	int				i;
	int				nb_tetriminos;
	int				nb_dieze;
	int				nb_dot;
}					t_check_t;

typedef struct		s_tetris
{
	int				size_x;
	int				size_y;
	int				position;
	char			*piece;
	char			name;
	int				type;
}					t_tetris;

int					ft_pre_test(char *map);
int					ft_check_tetriminos(char *map, int *nb_tetriminos);
char				*ft_solve(char *map, t_tetris *p);
int					*ft_place_tetriminos(char *map);
int					ft_put_size_x1(int ps[5]);
int					ft_put_size_y1(int ps[5]);
char				*ft_put_piece1(int ps[5]);
void				ft_init_tetris(int nb_tetriminos, char *input, t_tetris *p);
void				ft_new_map(int size_map, char *map, t_tetris *p);
void				ft_init_positions(t_tetris *pp);
void				ft_endmap(char *map, t_tetris *p, int y[2], int *i);
void				ft_delete_piece(char *map, char c);
void				ft_print_color(char *str, t_tetris *p);
int					ft_what_type(char *piece);

#endif
