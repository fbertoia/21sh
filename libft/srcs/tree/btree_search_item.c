/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:08:16 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:08:18 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*btree_search_item(t_btree *root,
	void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree *ret;

	if (!root)
		return (NULL);
	if (cmpf(data_ref, root->content) == 0)
		return (root);
	else if ((ret = btree_search_item(root->left, data_ref, cmpf)))
		return (ret);
	else if ((ret = btree_search_item(root->right, data_ref, cmpf)))
		return (ret);
	else
		return (NULL);
}
