/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:42:01 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/05 20:09:47 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFSIZE 100

typedef	struct		s_infos
{
	char	vide;
	char	obst;
	char	item;
}					t_infos;

typedef struct		s_point
{
	int		x;
	int		y;
	int		size;
}					t_point;

typedef struct		s_caract
{
	int				err;
	unsigned int	st_size;
	int				start_square;
	t_point			*square;
	int				colum;
	int				ligne;
	int				fd;
	char			**double_buff;
	char			*simple_buff;
	int				**buff_int;
}					t_caract;

void				ft_readbsq_stdin(t_caract *bsq, t_infos *elem);
void				ft_readbsq_file(char *av, t_caract *bsq, t_infos *elem);
int					ft_open(char *av, t_caract *bsq);
void				ft_position(t_caract *bsq);
int					ft_bsq_resolve(t_infos *elem, t_caract *bsq, int y, int x);
int					ft_bsq_not_resolve(int x, int y, t_caract *bsq);
void				ft_buff_int(t_caract *bsq, t_infos *elem, int x, int y);
void				ft_bsq(t_caract *bsq, t_infos *elem, int x, int y);
int					ft_conversion(t_infos *elem, int x, int y, t_caract *bsq);
void				ft_putstr(int i, char *str);
void				ft_map_error(t_caract *bsq);
void				ft_print_bsq(char **str, t_caract *bsq);
void				ft_double_buff(t_caract *bsq);
void				ft_alloc_line(t_caract *bsq, int i, int j, int k);
int					ft_how_cols(int min, char *buff);
void				ft_tcheck_getnbr(t_caract *bsq, int j, int i, int err);
int					ft_getnbr(t_caract *bsq, int max);
void				ft_size_map_again(t_caract *bsq, int i, int z, int start);
void				ft_tcheck_size_map(t_caract *bsq, int i);
void				ft_tcheck_elem_map(t_caract *bsq,
					t_infos *elem, int i, int back_n);
void				ft_check(t_caract *bsq, t_infos *elem);
void				ft_buff_size(t_caract *bsq);
char				*ft_buff_size_stdin(t_caract *bsq);
int					ft_size_file(char *av, int err);
int					ft_strlen(char *str);
int					ft_size_elem(t_caract *bsq);
void				ft_check_first_elem(t_caract *bsq, t_infos *elem, int i);
void				ft_free_buff_char(t_caract *bsq);
void				ft_free_buff_int(t_caract *bsq);
void				ft_free_lines_char(t_caract *bsq, int j);
void				ft_free_lines_int(t_caract *bsq, int j);
void				ft_free_all(t_caract *bsq, t_infos *elem);

#endif
