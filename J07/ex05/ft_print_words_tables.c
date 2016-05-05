/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 11:24:21 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/06 07:53:00 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int j;
	int c;

	c = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j][c] != '\0')
		{
			ft_putchar(tab[j][c]);
			c++;
		}
		c = 0;
		ft_putchar('\n');
		j++;
	}
}
