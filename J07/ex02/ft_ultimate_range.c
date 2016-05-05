/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 10:13:09 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/06 07:45:34 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*tab;

	tab = 0;
	len = 0;
	if (min < max)
	{
		if ((tab = (int*)malloc(sizeof(*tab) * (max - min + 1))) == 0)
			return (0);
		while (min < max)
		{
			tab[len] = min;
			len++;
			min++;
		}
		tab[len] = '\0';
		*range = tab;
		return (len);
	}
	else
	{
		tab = NULL;
		*range = tab;
		return (0);
	}
}
