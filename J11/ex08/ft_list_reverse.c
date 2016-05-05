/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:33:49 by aanzieu           #+#    #+#             */
/*   Updated: 2016/01/17 19:18:05 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list *list;
	t_list *new_list;
	t_list *next;

	list = *begin_list;
	new_list = NULL;
	while (list)
	{
		next = list->next;
		list->next = new_list;
		new_list = list;
		list = next;
	}
	*begin_list = new_list;
}
