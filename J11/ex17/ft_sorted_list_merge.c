/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:33:49 by aanzieu           #+#    #+#             */
/*   Updated: 2016/01/23 16:01:50 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_swap(t_list **tmp1, t_list **tmp2)
{
	t_list	*tmp_data;

	tmp_data = (*tmp1)->data;
	(*tmp1)->data = (*tmp2)->data;
	(*tmp2)->data = tmp_data;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	int		i;

	i = 1;
	if ((*begin_list)->next == NULL)
		return ;
	while (i)
	{
		i = 0;
		tmp = *begin_list;
		while (tmp->next)
		{
			if ((*cmp)(tmp->data, (tmp->next)->data) > 0)
			{
				ft_swap(&tmp, &tmp->next);
				i = 1;
			}
			tmp = tmp->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else if ((*begin_list1)->next == NULL)
		(*begin_list1)->next = begin_list2;
	else
		ft_sorted_list_merge(&(*begin_list1)->next, begin_list2, cmp);
	ft_list_sort(begin_list1, cmp);
}
