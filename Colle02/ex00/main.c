/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 18:42:32 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/01 18:58:19 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "colle.h"

int	ft_atoi(char *str)
{
	int total;
	int i;
	int nega;

	i = 0;
	total = 0;
	nega = 0;
	while ((str[i] < '0' && str[i] > '9') && str[i] != '-' && str[i] != '+')
		i++;
	if (str[i] == '-')
		nega = 1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10;
		total = total + ((int)str[i] - '0');
		i++;
	}
	if (nega)
		total = -total;
	return (total);
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	char	*courage;

	courage = "aucune";
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (argc == 3)
	{
		colle(x, y);
	}
	if (argc == 0 || argc > 3)
	{
		ft_putstr(courage);
		ft_putchar('\n');
	}
	return (0);
}
