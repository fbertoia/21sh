/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:08:07 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:08:09 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_insert_data(t_btree **root,
	void *item, int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (!(*root))
		*root = btree_create_node(*root, item);
	else if (cmpf(item, (*root)->right) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
