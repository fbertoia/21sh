/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:51:02 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 14:51:04 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	del_lex(void **lex)
{
	t_lex **elem;

	elem = (t_lex**)lex;
	ft_strdel(&(*elem)->content);
	ft_memdel(lex);
}
