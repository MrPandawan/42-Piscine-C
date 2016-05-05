/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:38:33 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/20 19:06:44 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_power(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		nb = nb * -1;
	while (nb > 9)
	{
		i = i * 10;
		nb = nb / 10;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	int x;

	x = ft_power(nb);
	if (nb == 0)
		ft_putchar(48);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		while (x != 0)
		{
			ft_putchar('0' + nb / x);
			nb = nb - nb / x * x;
			x = x / 10;
		}
	}
}
