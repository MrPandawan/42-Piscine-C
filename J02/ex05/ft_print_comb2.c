/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 16:03:17 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/20 19:00:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int w;
	int x;

	w = 0;
	while (w <= 98)
	{
		x = w + 1;
		while (x <= 99)
		{
			ft_putchar('0' + w / 10);
			ft_putchar('0' + w % 10);
			ft_putchar(' ');
			ft_putchar('0' + x / 10);
			ft_putchar('0' + x % 10);
			if (w != 98)
				ft_putchar(',');
			if (w != 98)
				ft_putchar(' ');
			x++;
		}
		w++;
	}
}
