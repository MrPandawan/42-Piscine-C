/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 16:03:17 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/20 19:04:45 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_nbr(int n)
{
	int i;

	i = 0;
	while (i < n)
		ft_putchar(i);
		i++;
	return (i);
}

void	ft_print_combn(int n)
{
	int x;

	x = ft_nbr(n);
	while (x <= '9')
	{
		ft_putchar('0' + x + 1);
		if (x != '9')
		ft_putchar(',');
		if (x != '9')
		ft_putchar(' ');
		x++;
	}
}
