/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:18:42 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/14 21:51:27 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFSIZE 16
# define HEXA "0123456789abcdef"
# define C "-C"

void	print_with_c(int off);
void	print_without_c(int off);
int		print_hexa_without_c(int i, int offset, int fd, char **av);
void	ft_hexa_without_c(int ac, char **av);
int		print_hexa_with_c(int i, int offset, int fd, char **av);
void	ft_hexa_with_c(int ac, char **av);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_strcmp(char *str1, char *str2);
int		size_files(int i, char **av);
char	*copy_line(char c, int sf, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr_base(int n, char *base);
void	ft_putnbr_base2(int n, char *base);
void	ft_print_without_c(int n);
void	ft_print_with_c(int n);
void	final_line_option(char *buf, int i);
void	ft_blanc_option(char *str);
void	ft_error(int fd, char **av, int i);
void	hexa_buff_with_c(char *buf);
void	hexa_buff_without_c(char *buf);
void	ft_last_line2(int i, char **av, int j, int fd);
void	ft_last_line(int i, char **av, int j, int fd);

#endif
