/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 22:21:33 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/05 20:11:55 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i);
}

int				ft_how_cols(int min, char *buff)
{
	int	i;
	int	cols_nbr;

	cols_nbr = 1;
	i = 0;
	while (i <= min)
		i += 1;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		cols_nbr++;
		i++;
	}
	return (cols_nbr);
}

static int		ft_generate_int(char *str, int index, int max)
{
	int result;

	result = 0;
	while (str[index] >= 48 && str[index] <= 57 && index < max - 3)
	{
		result = (result * 10) + (str[index] - 48);
		index = index + 1;
	}
	return (result);
}

int				ft_getnbr(t_caract *bsq, int max)
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (index < max)
	{
		if (bsq->simple_buff[index] >= 48 && bsq->simple_buff[index] <= 57)
		{
			result = ft_generate_int(bsq->simple_buff, index, max);
			return (result);
		}
		else
		{
			ft_map_error(bsq);
			return (0);
		}
		index = index + 1;
	}
	return (0);
}

void			ft_tcheck_getnbr(t_caract *bsq, int i, int j, int err)
{
	while (j < (i - 3))
	{
		if (bsq->simple_buff[j] < 48 || bsq->simple_buff[j] > 57)
			err += 1;
		j++;
	}
	if (err > 0)
	{
		ft_map_error(bsq);
		return ;
	}
}
