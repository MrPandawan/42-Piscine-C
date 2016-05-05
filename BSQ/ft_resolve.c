/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:10:55 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/05 18:11:54 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_bsq(t_caract *bsq, t_infos *elem, int x, int y)
{
	while (y < (bsq->square->y + bsq->square->size))
	{
		while (x < (bsq->square->x + bsq->square->size))
		{
			bsq->double_buff[y][x] = elem->item;
			x++;
		}
		x -= bsq->square->size;
		y++;
	}
}

int		ft_bsq_not_resolve(int x, int y, t_caract *bsq)
{
	int algo[4];
	int i;

	i = 0;
	algo[0] = bsq->buff_int[y][x - 1];
	algo[1] = bsq->buff_int[y - 1][x - 1];
	algo[2] = bsq->buff_int[y - 1][x];
	algo[3] = 2147483647;
	while (i < 3)
	{
		if (algo[3] > algo[i])
			algo[3] = algo[i];
		i++;
	}
	algo[3]++;
	if (algo[3] > bsq->square->size)
	{
		bsq->square->size = algo[3];
		bsq->square->x = x - (algo[3] - 1);
		bsq->square->y = y - (algo[3] - 1);
	}
	return (algo[3]);
}

int		ft_bsq_resolve(t_infos *elem, t_caract *bsq, int y, int x)
{
	if (bsq->double_buff[y][x] == elem->vide)
	{
		if (1 > bsq->square->size)
		{
			bsq->square->size = 1;
			bsq->square->x = x;
			bsq->square->y = y;
		}
		return (1);
	}
	else
		return (0);
}

int		ft_conversion(t_infos *elem, int x, int y, t_caract *bsq)
{
	if (y == 0 || x == 0)
		return (ft_bsq_resolve(elem, bsq, y, x));
	else
	{
		if (bsq->double_buff[y][x] == elem->obst)
			return (0);
		else
			return (ft_bsq_not_resolve(x, y, bsq));
	}
}

void	ft_buff_int(t_caract *bsq, t_infos *elem, int x, int y)
{
	if ((bsq->buff_int = (int**)malloc(sizeof(int *) * bsq->ligne)) == NULL)
		ft_map_error(bsq);
	while (x < bsq->colum && y < bsq->ligne)
	{
		if ((bsq->buff_int[y] = malloc(sizeof(int) * bsq->colum)) == NULL)
		{
			ft_putstr(2, "map error\n");
			ft_free_buff_char(bsq);
			ft_free_lines_int(bsq, y);
			free(bsq->buff_int);
			free(bsq);
			bsq->err = 1;
			return ;
		}
		while (x < bsq->colum)
		{
			bsq->buff_int[y][x] = ft_conversion(elem, x, y, bsq);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}
