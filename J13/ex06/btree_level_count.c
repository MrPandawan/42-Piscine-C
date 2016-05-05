/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:35:21 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/14 19:20:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		btree_level_count(t_btree *root)
{
	if (root == NULL)
		return (0);
	else
		return (ft_max(btree_level_count(root->left),
		btree_level_count(root->right)) + 1);
}
