/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:34:46 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/06 22:30:14 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check(t_caract *bsq, t_infos *elem)
{
	if (bsq->err == 1)
		return ;
	ft_check_first_elem(bsq, elem, 0);
	if (bsq->err == 1)
		return ;
	ft_tcheck_size_map(bsq, 0);
	if (bsq->err == 1)
		return ;
	ft_size_map_again(bsq, 0, 0, 0);
	if (bsq->err == 1)
		return ;
	ft_tcheck_elem_map(bsq, elem, 0, 0);
	if (bsq->err == 1)
		return ;
	ft_double_buff(bsq);
	if (bsq->err == 1)
		return ;
}

void	ft_position(t_caract *bsq)
{
	if ((bsq->square = malloc(sizeof(t_point))) == 0)
	{
		ft_map_error(bsq);
	}
	bsq->square->x = 0;
	bsq->square->y = 0;
	bsq->square->size = 0;
}

void	ft_readbsq_stdin(t_caract *bsq, t_infos *elem)
{
	if ((bsq->simple_buff = ft_buff_size_stdin(bsq)) == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	bsq->simple_buff[bsq->st_size] = '\0';
	if (bsq->err == 1)
		return ;
	ft_check(bsq, elem);
	if (bsq->err == 1)
		return ;
	ft_position(bsq);
	if (bsq->err == 1)
		return ;
	ft_buff_int(bsq, elem, 0, 0);
	if (bsq->err == 1)
		return ;
	ft_bsq(bsq, elem, bsq->square->x, bsq->square->y);
	if (bsq->err == 1)
		return ;
	ft_print_bsq(bsq->double_buff, bsq);
	if (bsq->err == 1)
		return ;
	ft_free_all(bsq, elem);
}

void	ft_readbsq_file(char *av, t_caract *bsq, t_infos *elem)
{
	bsq->err = 0;
	bsq->fd = ft_open(av, bsq);
	if (bsq->err == 1)
		return ;
	bsq->st_size = ft_size_file(av, bsq->err);
	ft_buff_size(bsq);
	if (bsq->err == 1)
		return ;
	ft_check(bsq, elem);
	if (bsq->err == 1)
		return ;
	ft_position(bsq);
	if (bsq->err == 1)
		return ;
	ft_buff_int(bsq, elem, 0, 0);
	if (bsq->err == 1)
		return ;
	ft_bsq(bsq, elem, bsq->square->x, bsq->square->y);
	if (bsq->err == 1)
		return ;
	ft_print_bsq(bsq->double_buff, bsq);
	if (bsq->err == 1)
		return ;
	ft_free_all(bsq, elem);
}

int		main(int ac, char **av)
{
	int			i;
	t_caract	*bsq;
	t_infos		*elem;

	i = 1;
	if (ac == 1)
	{
		if ((bsq = (t_caract *)malloc(sizeof(t_caract))) == NULL)
			return (0);
		if ((elem = malloc(sizeof(t_infos))) == NULL)
			return (0);
		ft_readbsq_stdin(bsq, elem);
		return (0);
	}
	while (i < ac)
	{
		if ((bsq = (t_caract *)malloc(sizeof(t_caract))) == NULL)
			i++;
		if ((elem = malloc(sizeof(t_infos))) == NULL)
			ft_map_error(bsq);
		ft_readbsq_file(av[i], bsq, elem);
		i++;
	}
	return (0);
}
