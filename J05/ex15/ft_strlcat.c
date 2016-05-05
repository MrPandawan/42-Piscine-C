/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 09:00:15 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/29 22:18:11 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int x;
	unsigned int y;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (src[x] != '\0' && x < size - 1)
	{
		dest[i + x] = src[x];
		x++;
	}
	dest[i + x] = '\0';
	return (i + x);
}
