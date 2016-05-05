/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:00:38 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/15 18:22:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	final_line_option(char *buf, int i)
{
	ft_putchar(' ');
	while (buf && buf[i])
	{
		if (buf[i] == '\n' || buf[i] == '\t' || buf[i] == '\0')
			buf[i] = '.';
		i++;
	}
	ft_putchar('|');
	ft_putstr(buf);
	ft_putstr("|\n");
}

void	print_with_c(int off)
{
	ft_print_with_c(off);
	ft_putchar('\n');
}

void	print_without_c(int off)
{
	ft_print_without_c(off);
	ft_putchar('\n');
}
