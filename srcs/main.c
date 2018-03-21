/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:26:22 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/20 18:24:11 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "ast.h"
#include "lexer.h"

t_lex		*g_err_lex;

int			main(int argc, char *argv[])
{
	t_sh21			*sh21;
	extern char		**environ;

	sh21 = sh21_init(argc, argv, environ);
	opentty(&sh21->input);
	all_signal();
	if (!sh21->terminal.isatty || argv[1])
		input_piped_script(sh21, argv);
	sh21->ret = 0;
	while (1)
	{
		init_term(sh21);
		input_init(&sh21->input, 0);
		input_get(&sh21->input);
		reinit_term(sh21);
		lexer(sh21);
		if (parser(sh21->lex))
			sh21_get()->ret = exec_tree(sh21->tree.root_node);
		del_sh21();
	}
	return (0);
}
