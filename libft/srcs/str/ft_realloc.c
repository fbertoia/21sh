/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:12:53 by hfontain          #+#    #+#             */
/*   Updated: 2018/02/15 18:14:45 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t sz)
{
	void	*new;

	if (!ptr)
		return (NULL);
	new = ft_memalloc(sz);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, sz);
	ft_memdel((void *)&ptr);
	return (new);
}
