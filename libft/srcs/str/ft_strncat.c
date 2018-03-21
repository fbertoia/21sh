/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:36:16 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 16:18:00 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = s1;
	i = 0;
	while (*tmp)
	{
		tmp++;
	}
	while (i < n && *s2)
	{
		*tmp = *s2;
		tmp++;
		s2++;
		i++;
	}
	*tmp = 0;
	return (s1);
}
