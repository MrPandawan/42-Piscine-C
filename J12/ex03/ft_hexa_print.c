/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:53:46 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/15 18:32:51 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hexa_buff_with_c(char *buf)
{
	int i;

	i = 0;
	ft_putstr("  ");
	while (buf && buf[i])
	{
		if (i == 8 || i == 16)
			ft_putchar(' ');
		if (buf[i] >= 0 && buf[i] <= 15)
			ft_putchar('0');
		ft_putnbr_base(buf[i], HEXA);
		ft_putchar(' ');
		i++;
	}
	if (ft_strlen(buf) < BUFSIZE)
	{
		if (i <= 8)
			i = (ft_strlen(buf) * 3) - 1;
		else if (i > 8)
			i = (ft_strlen(buf) * 3);
		while (++i != 49)
			ft_putchar(' ');
	}
}

void	hexa_buff_without_c(char *buf)
{
	int i;

	i = 0;
	ft_putchar(' ');
	while (buf && buf[i])
	{
		if (buf[i] >= 0 && buf[i] <= 15)
			ft_putchar('0');
		ft_putnbr_base(buf[i], HEXA);
		if (i < 15)
			ft_putchar(' ');
		i++;
	}
	if (ft_strlen(buf) < BUFSIZE)
	{
		i = (ft_strlen(buf) * 3);
		while (++i < 48)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	ft_last_line2(int i, char **av, int j, int fd)
{
	int		x;
	int		y;
	char	copy;
	char	*stock;

	x = size_files(i, av);
	fd = open(av[i], O_RDONLY);
	y = 0;
	while (y < (x - (x % 16)))
		y += read(fd, &copy, 1);
	stock = ft_strdup(copy_line(copy, x, fd));
	ft_print_without_c(j);
	hexa_buff_without_c(stock);
	if (!av[++i])
	{
		ft_print_without_c(j + (x % 16));
		ft_putchar('\n');
	}
	close(fd);
}

void	ft_last_line(int i, char **av, int j, int fd)
{
	int		x;
	int		y;
	char	copy;
	char	*stock;

	x = size_files(i, av);
	fd = open(av[i], O_RDONLY);
	y = 0;
	while (y < (x - (x % 16)))
		y += read(fd, &copy, 1);
	stock = ft_strdup(copy_line(copy, x, fd));
	ft_print_with_c(j);
	hexa_buff_with_c(stock);
	final_line_option(stock, 0);
	if (!av[++i] && x % 16 != 0)
	{
		ft_print_with_c(j + (x % 16));
		ft_putchar('\n');
	}
	close(fd);
}

void	ft_error(int fd, char **av, int i)
{
	if (fd < 0)
	{
		ft_putstr("hexdump: ");
		ft_putstr(av[i]);
		ft_putstr(": No such file or directory\n");
		if (!av[++i])
		{
			ft_putstr("hexdump: ");
			ft_putstr(av[--i]);
			ft_putstr(": Bad file descriptor\n");
		}
	}
}
