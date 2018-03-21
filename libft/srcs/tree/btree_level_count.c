/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:08:12 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:08:13 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			btree_level_count(t_btree *root)
{
	int left_size;
	int right_size;

	if (!root)
		return (0);
	left_size = btree_level_count(root->left) + 1;
	right_size = btree_level_count(root->right) + 1;
	return (ft_max(left_size, right_size));
}
