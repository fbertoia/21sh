/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:07:49 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:07:50 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_apply_prefix(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	applyf(root->content);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
