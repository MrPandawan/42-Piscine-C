/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:28:22 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/06 18:43:59 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_buff_char(t_caract *bsq)
{
	int	i;

	i = 0;
	while (i < bsq->ligne)
	{
		free(bsq->double_buff[i]);
		i += 1;
	}
	free(bsq->double_buff);
}

void	ft_free_buff_int(t_caract *bsq)
{
	int	i;

	i = 0;
	while (i < bsq->ligne)
	{
		free(bsq->buff_int[i]);
		i += 1;
	}
	free(bsq->buff_int);
}

void	ft_free_lines_char(t_caract *bsq, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(bsq->double_buff[i]);
		i += 1;
	}
}

void	ft_free_lines_int(t_caract *bsq, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(bsq->buff_int[i]);
		i += 1;
	}
}

int		ft_open(char *av, t_caract *bsq)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		free(bsq);
		bsq->err = 1;
		return (0);
	}
	return (fd);
}
