/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:33:49 by aanzieu           #+#    #+#             */
/*   Updated: 2016/01/17 11:53:22 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		(*g_f[5])(int, int) = {ft_add, ft_sub, ft_mul, ft_div, ft_mod};

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_op(char *str)
{
	int		k;
	char	op[6];

	ft_strcpy(op, "+-*/%");
	k = 0;
	while (op[k])
	{
		if (op[k] == str[0])
			return (k);
		k++;
	}
	return (-1);
}

int		ft_ok(int j, int op)
{
	if (op < 0)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	if (j == 0 && op > 2)
	{
		if (op == 4)
			ft_putstr("Stop : modulo by zero\n");
		if (op == 3)
			ft_putstr("Stop : division by zero\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		op;

	if (argc != 4)
		return (0);
	i = ft_atoi(argv[1]);
	j = ft_atoi(argv[3]);
	op = ft_op(argv[2]);
	if (ft_ok(j, op))
	{
		ft_putnbr((long)(*g_f[op])(i, j));
		ft_putchar('\n');
	}
	return (0);
}
