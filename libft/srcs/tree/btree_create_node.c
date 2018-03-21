/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:56:29 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/13 12:49:35 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree		*btree_create_node(t_btree *parent, void *item)
{
	t_btree *ret;

	if (!(ret = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	ret->left = NULL;
	ret->right = NULL;
	ret->parent = parent;
	ret->content = item;
	return (ret);
}
