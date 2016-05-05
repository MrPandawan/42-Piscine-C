/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 10:50:21 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/06 18:05:44 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(int argc, char **argv)
{
	int len;
	int i;

	len = 0;
	while (len < argc)
	{
		i = 0;
		while (argv[i] != '\0')
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		k;
	int		i;
	int		j;
	char	*newargv;

	newargv = (char*)malloc(sizeof(*newargv) * (ft_len(argc, argv) + argc));
	k = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			newargv[k] = argv[i][j];
			j++;
			k++;
		}
		if (i < argc - 1)
			newargv[k++] = '\n';
		i++;
	}
	newargv[k] = '\0';
	return (newargv);
}
