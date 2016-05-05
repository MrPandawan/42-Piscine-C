/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 09:42:09 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/24 18:17:49 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int num;

	num = 1;
	i = 1;
	if (nb == 0)
		return (1);
	else if (nb > 12 || nb < 0)
		return (0);
	else
		while (i <= nb)
		{
			num = num * i;
			i++;
		}
	return (num);
}
