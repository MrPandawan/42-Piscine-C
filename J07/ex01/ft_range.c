/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 09:09:37 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/06 07:45:25 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		len;
	int		*tab;

	tab = 0;
	len = 0;
	if (min < max)
	{
		if ((tab = (int*)malloc(sizeof(*tab) * (max - min))) == 0)
			return (NULL);
		while (min < max)
		{
			tab[len] = min;
			len++;
			min++;
		}
		tab[len] = '\0';
		return (tab);
	}
	else
		return (tab);
}
