/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 09:45:22 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/24 22:32:03 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb > 12 || nb < 0)
		return (0);
	else
	{
		if (nb > 1)
			nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
}
