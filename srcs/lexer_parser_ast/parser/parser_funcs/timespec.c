/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timespec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:59:42 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 18:03:37 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexer.h"

t_lex	*timespec(t_lex *lex)
{
	if (!assert_lex(lex))
		return (g_err_lex);
	if (assert_lex(lex) && ft_strequ(lex->content, "-p"))
		return ((lex->next));
	return (lex);
}
