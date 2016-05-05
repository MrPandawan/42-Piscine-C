/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 10:56:32 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/18 21:53:16 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	colle(int x, int y)
{
	int l;
	int h;

	h = 0;
	if (x > 0 && y > 0)
	{
		while (h++ < y)
		{
			l = 0;
			while (l++ < x)
			{
				if ((l == 1 && h == 1) || (l == x && h == y && l != 1))
					ft_putchar('A');
				else if ((l == x && h == 1) || (h == y && l == 1))
					ft_putchar('C');
				else if ((l < x && h == 1) || (h < y && l == 1)
						|| (l == x && h < y) || (l < x && h == y))
					ft_putchar('B');
				else
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
	}
}
