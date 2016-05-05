/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:33:49 by aanzieu           #+#    #+#             */
/*   Updated: 2016/01/23 14:20:55 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *front;

	front = ft_create_elem(data);
	if (*begin_list)
		front->next = *begin_list;
	*begin_list = front;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (++i < ac)
	{
		ft_list_push_front(&tmp, av[i]);
	}
	return (tmp);
}
