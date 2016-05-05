/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:33:49 by aanzieu           #+#    #+#             */
/*   Updated: 2016/01/23 15:58:09 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int		ft_list_push(t_list **begin_list, t_list **new_list, void *data,
		int (*cmp)())
{
	t_list	*elem;

	if ((*cmp)((*new_list)->data, data) > 0)
	{
		elem = ft_create_elem(data);
		(*begin_list)->next = elem;
		elem->next = *new_list;
		return (1);
	}
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	i = 1;
	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp1 = *begin_list;
	tmp2 = tmp1->next;
	while (tmp2)
	{
		if (ft_list_push(&tmp1, &tmp2, data, cmp))
			return ;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	tmp1->next = ft_create_elem(data);
}
