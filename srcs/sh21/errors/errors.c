/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:04:12 by hfontain          #+#    #+#             */
/*   Updated: 2018/02/19 18:52:35 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_error(int err, const char *s)
{
	if (err >= 0)
		ft_dprintf(2, "%[RED]21sh%[NC]: %s: %s\n", s, g_errno_message[err]);
	else
	{
		err = -err;
		ft_dprintf(2, "%[RED]21sh%[NC]: %s: %s\n", s, g_own_message[err]);
	}
	return (err);
}
