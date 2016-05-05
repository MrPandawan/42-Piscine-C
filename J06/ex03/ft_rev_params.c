/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:36:47 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/28 20:49:37 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int x;
	int y;

	x = argc - 1;
	y = 0;
	while (x > 0)
	{
		while (argv[x][y])
		{
			ft_putchar(argv[x][y]);
			y++;
		}
		ft_putchar('\n');
		y = 0;
		x--;
	}
	return (0);
}
