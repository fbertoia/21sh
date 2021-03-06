/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexutils_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:35:41 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/13 17:57:51 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "sh21.h"
#include "libft.h"

void		on_word(t_lexa *lexa)
{
	lexa->t = WORD;
	lexa->buffer = ft_strpushback(lexa->buffer, lexa->c, &g_lexa_buff_sz);
}

void		lexfallback(t_lexa *lexa)
{
	lexa->stat = SWORD;
	lexa->t = WORD;
	lexa->buffer = ft_strpushback(lexa->buffer, lexa->c, &g_lexa_buff_sz);
}

void		lexa_init(t_lexa *lexa, t_sh21 *sh21)
{
	lexa->str = sh21->input.buff;
	lexa->stat = SNIL;
	lexa->prev = '\0';
	lexa->t = EOI;
	lexa->lex = NULL;
	lexa->oquote = 0;
	lexa->buffer = ft_strnew(0);
}

void		loop_word(t_lex *ptr)
{
	int		i;

	i = If;
	while (i <= In)
	{
		if (ft_strequ(ptr->content, g_token_type_str[i]))
		{
			ptr->token_type = i;
			break ;
		}
		++i;
	}
}

void		word_recog(t_lexa *lexa)
{
	t_lex			*ptr;
	t_token_type	token_last_elem;

	ptr = lexa->lex;
	token_last_elem = BEGIN;
	while (ptr)
	{
		if (ptr->token_type == WORD || ptr->token_type == IO_NUM_SPC)
		{
			if (ptr->token_type == IO_NUM_SPC)
				ptr->token_type = WORD;
			else if (str_digit(ptr->content) &&
				((ptr->next && is_redir_part(ptr->next->content[0]))
							|| is_redir_token(token_last_elem)))
				ptr->token_type = IO_NUMBER;
			else
				loop_word(ptr);
		}
		token_last_elem = ptr->token_type;
		ptr = ptr->next;
	}
}
