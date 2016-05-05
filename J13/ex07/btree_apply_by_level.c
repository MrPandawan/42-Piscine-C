/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:35:44 by aanzieu           #+#    #+#             */
/*   Updated: 2016/02/15 19:46:28 by aanzieu          ###   ########.fr       */
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

void	ft_level(t_btree *root, int lvl, int elem,
		void (*f)(void *item, int current_level, int is_first_elem))
{
	if (root)
		return ;
	if (lvl == elem)
		(*f)(root->left, lvl, 0);
	else
	{
		ft_level(root->left, lvl + 1, elem, f);
		ft_level(root->right, lvl + 1, elem, f);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*apply)(void *item, int current_level, int is_first_elem))
{
	int	i;
	int	j;

	i = btree_level_count(root);
	j = 0;
	while (j < i)
	{
		ft_level(root, 0, j, apply);
		j++;
	}
}
