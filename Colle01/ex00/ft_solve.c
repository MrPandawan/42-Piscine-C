/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 22:02:45 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/25 22:24:00 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ligne(int nb, char **argv, int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (argv[i][j] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		ft_col(int nb, char **argv, int j)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (argv[i][j] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		ft_block(int nb, char **argv, int i, int j)
{
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			if (argv[i][j] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_solve(char **argv, int j, int i)
{
	int nb;

	nb = 1;
	if (argv[i][j] == '\0')
		return (0);
	else
	{
		while (nb <= 9)
		{
			if (ft_block(nb, argv, i, j)
					&& ft_col(nb, argv, j) && ft_ligne(nb, argv, i))
				argv[i][j] = nb;
			else
				argv[i][j] = 0;
			nb++;
		}
	}
	return (1);
}
