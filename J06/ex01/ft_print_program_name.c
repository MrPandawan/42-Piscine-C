/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 10:40:17 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/29 17:22:28 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int y;

	y = 0;
	if (argc > 1)
		return (0);
	else
	{
		while (argv[0][y] != '\0')
		{
			ft_putchar(argv[0][y]);
			y++;
		}
		ft_putchar('\n');
	}
	return (0);
}
