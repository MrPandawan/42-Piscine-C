/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:34:46 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/06 18:42:16 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(int i, char *str)
{
	int	j;

	j = 0;
	while (str[j++])
		;
	write(i, str, j);
	return ;
}

void	ft_map_error(t_caract *bsq)
{
	write(1, "map error\n", 10);
	free(bsq->simple_buff);
	bsq->err = 1;
}

void	ft_print_bsq(char **str, t_caract *bsq)
{
	int i;

	i = 0;
	while (i < bsq->ligne)
	{
		write(1, str[i], bsq->colum);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_alloc_line(t_caract *bsq, int i, int j, int k)
{
	int l;

	l = 0;
	while (l < bsq->ligne)
	{
		if ((bsq->double_buff[l] = malloc(sizeof(char) * bsq->colum)) == NULL)
		{
			write(1, "map error\n", 10);
			ft_free_lines_char(bsq, l);
			free(bsq->simple_buff);
			free(bsq->double_buff);
			bsq->err = 1;
			return ;
		}
		while (k < bsq->colum)
		{
			bsq->double_buff[l][k] = bsq->simple_buff[i + j];
			j++;
			k++;
		}
		j++;
		k = 0;
		l++;
	}
}

void	ft_double_buff(t_caract *bsq)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (bsq->simple_buff[i] != '\n')
		i++;
	i += 1;
	if ((bsq->double_buff = malloc(sizeof(char *) * bsq->ligne)) == NULL)
	{
		ft_map_error(bsq);
		return ;
	}
	ft_alloc_line(bsq, i, j, 0);
	free(bsq->simple_buff);
}
