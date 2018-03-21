/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:47:56 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/09 20:48:03 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "sh21.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;

	if (((tmp = (char *)malloc(sizeof(char) * size)) == NULL) || size > 100000)
		ft_exit(errno, "malloc");
	ft_bzero(tmp, size);
	return ((void *)tmp);
}
