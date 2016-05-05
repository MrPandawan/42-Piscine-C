/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdumpcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:49:36 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/15 18:18:50 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_hexa_without_c(int i, int offset, int fd, char **av)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 0;
	buf = (char*)malloc(sizeof(char) * BUFSIZE + 1);
	while ((read(fd, buf, BUFSIZE)))
	{
		buf[BUFSIZE] = '\0';
		ft_print_without_c(offset);
		hexa_buff_without_c(buf);
		bytes_read += 16;
		offset += 16;
		if (size_files(i, av) % 16 != 0 &&
		bytes_read == (size_files(i, av) / 16) * 16)
		{
			ft_last_line2(i, av, offset, fd);
			offset += (size_files(i, av) % 16);
			close(fd);
			break ;
		}
		else if (size_files(i, av) % 16 == 0 &&
		bytes_read == (size_files(i, av) / 16 * 16) && !av[++i])
			print_without_c(offset);
	}
	return (offset);
}

void	ft_hexa_without_c(int ac, char **av)
{
	int		i;
	int		offset;
	int		fd;

	i = 0;
	offset = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		ft_error(fd, av, i);
		if (fd >= 0)
			offset = print_hexa_without_c(i, offset, fd, av);
	}
}

int		print_hexa_with_c(int i, int offset, int fd, char **av)
{
	int		x;
	char	*buf;

	x = 0;
	buf = (char*)malloc(sizeof(char) * BUFSIZE + 1);
	while ((read(fd, buf, BUFSIZE)))
	{
		buf[BUFSIZE] = '\0';
		ft_print_with_c(offset);
		hexa_buff_with_c(buf);
		final_line_option(buf, 0);
		x += 16;
		offset += 16;
		if (size_files(i, av) % 16 != 0 && x == (size_files(i, av) / 16) * 16)
		{
			ft_last_line(i, av, offset, fd);
			offset += (size_files(i, av) % 16);
			close(fd);
			break ;
		}
		else if (size_files(i, av) % 16 == 0 &&
				x == (size_files(i, av) / 16 * 16) && !av[++i])
			print_with_c(offset);
	}
	return (offset);
}

void	ft_hexa_with_c(int ac, char **av)
{
	int		i;
	int		offset;
	int		fd;

	i = 1;
	offset = 0;
	fd = open(av[i], O_RDONLY);
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		ft_error(fd, av, i);
		if (fd >= 0)
			offset = print_hexa_with_c(i, offset, fd, av);
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	buf;

	if (ac < 2)
	{
		while (read(0, &buf, 1))
			write(1, &buf, 1);
	}
	i = 1;
	fd = open(av[i], O_RDONLY);
	if (open(av[i], O_RDONLY) < 0 && !av[2])
		ft_error(fd, av, i);
	else if (ft_strcmp(av[1], C) == 0)
		ft_hexa_with_c(ac, av);
	else if (ft_strcmp(av[1], C) != 0 && open(av[i], O_RDONLY) >= 0)
		ft_hexa_without_c(ac, av);
	return (0);
}
