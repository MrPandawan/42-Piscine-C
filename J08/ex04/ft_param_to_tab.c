/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 20:56:33 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/06 18:30:04 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int j;

	j = 0;
	while (str[j] != 0)
		j++;
	return (j);
}

char				*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*cpy;

	len = 0;
	while (src[len])
		len++;
	if ((cpy = (char*)malloc(sizeof(*cpy) * (len + 1))) == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *ptr;
	int			i;

	i = 0;
	if ((ptr = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))) == 0)
		return (NULL);
	while (i < ac)
	{
		ptr[i].size_param = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = ft_strdup(av[i]);
		ptr[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	ptr[i].str = 0;
	return (ptr);
}
