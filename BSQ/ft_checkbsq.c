/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 19:21:37 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/05 20:42:52 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_size_map_again(t_caract *bsq, int i, int z, int start)
{
	while (bsq->simple_buff[start] != '\n')
	{
		start += 1;
	}
	start += 1;
	while (i < bsq->ligne)
	{
		if (bsq->simple_buff[(i * bsq->colum) + (bsq->colum + i) + start]
				<= '\n')
			z++;
		else
		{
			ft_map_error(bsq);
			return ;
		}
		i++;
	}
	if (z != (bsq->ligne))
		ft_map_error(bsq);
}

void	ft_tcheck_size_map(t_caract *bsq, int i)
{
	int	lines_nbr;
	int	size_nbr;
	int	cols_nbr;
	int	back_n;

	while (bsq->simple_buff[i] != '\n')
	{
		if (bsq->simple_buff[i] == '\0')
			ft_map_error(bsq);
		i++;
	}
	ft_tcheck_getnbr(bsq, i, 0, 0);
	if (bsq->err == 1)
		return ;
	lines_nbr = ft_getnbr(bsq, i);
	cols_nbr = ft_how_cols((i + 1), bsq->simple_buff);
	size_nbr = lines_nbr * cols_nbr;
	back_n = (lines_nbr + 1);
	if (size_nbr != (((int)(bsq->st_size)) - i) - (back_n))
	{
		ft_map_error(bsq);
		return ;
	}
	bsq->ligne = lines_nbr;
	bsq->colum = cols_nbr;
}

void	ft_tcheck_elem_map(t_caract *bsq,
		t_infos *elem, int i, int back_n)
{
	while (bsq->simple_buff[i] != '\n')
		i++;
	while (bsq->simple_buff[i] != '\0')
	{
		if (bsq->simple_buff[i] == 10)
			back_n++;
		if ((bsq->simple_buff[i] != elem->vide && bsq->simple_buff[i]
					!= elem->obst) && bsq->simple_buff[i] != 10)
		{
			ft_map_error(bsq);
			return ;
		}
		i++;
	}
	if ((back_n - 1) != bsq->ligne)
	{
		ft_map_error(bsq);
		return ;
	}
}

int		ft_size_elem(t_caract *bsq)
{
	int i;

	i = 0;
	while (bsq->simple_buff[i] != 10)
		i++;
	return (i);
}

void	ft_check_first_elem(t_caract *bsq, t_infos *elem, int i)
{
	while (bsq->simple_buff[i] != '\n')
	{
		i++;
	}
	if (i < 4)
	{
		ft_map_error(bsq);
		return ;
	}
	elem->vide = bsq->simple_buff[i - 3];
	elem->obst = bsq->simple_buff[i - 2];
	elem->item = bsq->simple_buff[i - 1];
}
