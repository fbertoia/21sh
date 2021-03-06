/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:56:29 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/19 12:41:56 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "sh21.h"
#include "libft.h"

t_lex		*lex_create(t_token_type token_type, char *content)
{
	t_lex	*lex;

	lex = malloc(sizeof(t_lex));
	lex->content = ft_strdup(content);
	lex->token_type = token_type;
	lex->next = NULL;
	return (lex);
}

static int	end_lex(t_lexa *lexa, t_sh21 *sh21)
{
	int		prev_word;
	t_lex	*ptr;

	prev_word = 0;
	if (lexa->buffer)
		add_elem_back((void**)&lexa->lex,
			(void*)lex_create(lexa->t, lexa->buffer));
	word_recog(lexa);
	ptr = lexa->lex;
	while (ptr)
	{
		if (ptr->token_type == WORD)
		{
			if (prev_word == 0 && ft_strchr(ptr->content, '=') != NULL)
				ptr->token_type = ASSIGNMENT_WORD;
			else
				prev_word = 1;
		}
		else
			prev_word = 0;
		ptr = ptr->next;
	}
	lexa->buffer ? ft_strdel(&lexa->buffer) : (0);
	sh21->lex = lexa->lex;
	return (1);
}

int			lexer(t_sh21 *sh21)
{
	t_lexa		lexa;

	lexa_init(&lexa, sh21);
	while (*lexa.str)
	{
		lexa.c = *(lexa.str);
		check_semi_stat(&lexa);
		if (lexa.c == '"' || lexa.c == '\'')
			on_quote(&lexa);
		else if (lexa.oquote)
			lexa.buffer = ft_strpushback(lexa.buffer, lexa.c, &g_lexa_buff_sz);
		else if (lexa.c == ' ')
			on_blank(&lexa);
		else if (is_operator_part(lexa.prev, lexa.stat))
			on_operator_prev(&lexa);
		else if (is_operator_part(lexa.c, lexa.stat))
			on_operator(&lexa);
		else if (lexa.stat == SWORD)
			on_word(&lexa);
		else
			lexfallback(&lexa);
		lexa.prev = lexa.c;
		++(lexa.str);
	}
	return (end_lex(&lexa, sh21));
}
