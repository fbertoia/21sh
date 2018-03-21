/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:07:45 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:07:46 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->content);
	btree_apply_infix(root->right, applyf);
}
