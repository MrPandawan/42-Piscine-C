/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 13:29:04 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/25 22:10:58 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ligne(int nb, char **argv, int i);
int		ft_col(int nb, char **argv, int j);
int		ft_block(int nb, char **argv, int i, int j);
int		ft_solve(char **argv, int j, int i);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '.')
			{
				str[i][j] = '0';
			}
			j++;
		}
	i++;
	}
	return (**str);
}

void	ft_putstr(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '.')
		{
			ft_putchar('0');
			ft_putchar(' ');
		}
		else
		{
			ft_putchar(str[j]);
			ft_putchar(' ');
		}
		j++;
	}
}

int		main(int argc, char **argv)
{
	int j;
	int i;

	i = 1;
	j = 0;
	ft_str(argv);
	if (argc == 10)
		while (i < argc)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	else
	{
		write(1, "Erreur 42", 9);
		write(1, "\n", 1);
	}
	write(1, "on a pas reussi, desole, :(", 27);
	ft_putchar('\n');
	return (0);
}
