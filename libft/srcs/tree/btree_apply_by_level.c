/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:07:38 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:07:41 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_by_level2(t_btree *root, int level, int target,
	void (*applyf)(void *item))
{
	if (!root)
		return ;
	if (level == target)
	{
		applyf(root);
		return ;
	}
	btree_apply_by_level2(root->left, level + 1, target, applyf);
	btree_apply_by_level2(root->right, level + 1, target, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item))
{
	int size_level;
	int i;

	if (!root)
		return ;
	i = 0;
	size_level = btree_level_count(root);
	while (i < size_level)
	{
		btree_apply_by_level2(root->left, i, size_level, applyf);
		btree_apply_by_level2(root->right, i, size_level, applyf);
		i++;
	}
}
