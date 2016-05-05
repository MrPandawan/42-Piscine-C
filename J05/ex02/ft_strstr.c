/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 19:08:08 by aanzieu           #+#    #+#             */
/*   Updated: 2015/10/26 22:47:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	while (to_find[x] != '\0')
		x++;
	if (to_find == 0)
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (j == x - 1)
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
