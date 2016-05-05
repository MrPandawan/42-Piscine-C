/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 09:51:38 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/23 09:51:42 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index > 1)
	{
		index = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}
	return (index);
}
