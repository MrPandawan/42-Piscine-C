/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 16:49:40 by aanzieu           #+#    #+#             */
/*   Updated: 2015/11/06 07:52:41 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_word(char *str)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			word++;
			i++;
		}
	}
	return (word);
}

int		ft_len(char *str, int i)
{
	int len;

	len = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((tab = (char**)malloc(sizeof(*tab) * (ft_word(str) + 1))) == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			tab[j] = (char*)malloc(sizeof(**tab) * ft_len(str, i) + 1);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
