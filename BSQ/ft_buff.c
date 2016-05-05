/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:42:01 by aanzieu           #+#    #+#             */
/*   Updated: 2016/03/06 00:21:21 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_add2str(char *dest, char *src, size_t size)
{
	char	*temp;
	size_t	val_length;
	size_t	i;

	temp = (char*)malloc((size + 1) * sizeof(char));
	val_length = 0;
	while (dest != '\0' && dest[val_length])
	{
		temp[val_length] = dest[val_length];
		val_length++;
	}
	i = 0;
	while (i < (size - val_length))
	{
		temp[val_length + i] = src[i];
		i++;
	}
	temp[val_length + i] = '\0';
	free(dest);
	return (temp);
}

char	*ft_buff_size_stdin(t_caract *bsq)
{
	int		ret;
	size_t	size;
	char	buff[BUFFSIZE];
	char	*cpybuff;

	cpybuff = NULL;
	ret = 0;
	size = 0;
	while ((ret = read(0, buff, BUFFSIZE)))
	{
		buff[ret] = '\0';
		size += ret;
		cpybuff = ft_add2str(cpybuff, buff, size);
	}
	bsq->st_size = 0;
	bsq->st_size = size;
	bsq->simple_buff = (char*)malloc((sizeof(char) * bsq->st_size));
	if (bsq->simple_buff == NULL)
	{
		ft_map_error(bsq);
		return (0);
	}
	return (cpybuff);
}

void	ft_buff_size(t_caract *bsq)
{
	if (bsq->err == 1)
		return ;
	bsq->simple_buff = (char *)malloc((sizeof(char) * bsq->st_size) + 1);
	if (bsq->simple_buff == NULL)
	{
		ft_map_error(bsq);
		return ;
	}
	if (read(bsq->fd, bsq->simple_buff, bsq->st_size) <= 0)
	{
		ft_map_error(bsq);
		return ;
	}
	bsq->simple_buff[bsq->st_size] = '\0';
}

int		ft_size_file(char *av, int err)
{
	int		fd2;
	int		size;
	char	buffer;

	if (err == 1)
		return (0);
	size = 0;
	fd2 = open(av, O_RDONLY);
	while (read(fd2, &buffer, 1))
		size++;
	close(fd2);
	return (size);
}

void	ft_free_all(t_caract *bsq, t_infos *elem)
{
	free(elem);
	ft_free_buff_char(bsq);
	ft_free_buff_int(bsq);
	free(bsq->square);
	free(bsq);
}
