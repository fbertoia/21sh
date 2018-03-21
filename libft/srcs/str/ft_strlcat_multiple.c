/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multiple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:12:05 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/31 18:12:06 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strlcat_multiple(char *buff, size_t len, int nb_args, ...)
{
	va_list	ap;
	int		i;
	char	*tmp;

	i = 1;
	tmp = NULL;
	va_start(ap, nb_args);
	if (nb_args <= 0)
		return (NULL);
	ft_strlcpy(buff, va_arg(ap, char *), len);
	while (i < nb_args)
	{
		ft_strlcat(buff, va_arg(ap, char *), len);
		i++;
	}
	va_end(ap);
	return (buff);
}
