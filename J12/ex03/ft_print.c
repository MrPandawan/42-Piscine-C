/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:02:53 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/15 18:30:49 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *base)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[a] != '\0')
	{
		b = a + 1;
		if (base[a] == '+' || base[a] == '-')
			return (0);
		if (base[a] < ' ' || base[a] > '~')
			return (0);
		while (base[b] != '\0')
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	ft_putmaxneg_base(int nbr, char *base)
{
	if (nbr <= (-1 * ft_strlen(base)))
	{
		ft_putmaxneg_base(nbr / ft_strlen(base), base);
		ft_putmaxneg_base(nbr % ft_strlen(base), base);
	}
	else
		ft_putchar(base[-nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_atoi(base))
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putmaxneg_base(nbr, base);
			return ;
		}
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= ft_strlen(base))
		{
			ft_putnbr_base(nbr / ft_strlen(base), base);
			ft_putnbr_base(nbr % ft_strlen(base), base);
		}
		else
			ft_putchar(base[nbr]);
	}
}

void	ft_print_with_c(int n)
{
	if (n == 0)
		ft_putstr("0000000");
	else if (n == 16 || n < 256)
		ft_putstr("000000");
	else if (n == 256 || n < 4096)
		ft_putstr("00000");
	else if (n == 4096 || n < 65536)
		ft_putstr("0000");
	else if (n == 65536 || n < 1048576)
		ft_putstr("000");
	else if (n == 1048576 || n < 16777216)
		ft_putstr("00");
	else if (n == 16777216 || n < 268435456)
		ft_putstr("0");
	ft_putnbr_base(n, HEXA);
}

void	ft_print_without_c(int n)
{
	if (n == 0)
		ft_putstr("000000");
	else if (n == 16 || n < 256)
		ft_putstr("00000");
	else if (n == 256 || n < 4096)
		ft_putstr("0000");
	else if (n == 4096 || n < 65536)
		ft_putstr("000");
	else if (n == 65536 || n < 1048576)
		ft_putstr("00");
	else if (n == 1048576 || n < 16777216)
		ft_putstr("0");
	ft_putnbr_base(n, HEXA);
}
