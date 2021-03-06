/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:56:29 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/15 17:43:37 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "ft_printf.h"

# define SNIL	0
# define SOP	1
# define SWORD	2

# define DEBUG(lex)

/*
** {ft_dprintf(sh21_get()->debug_tty,
** "%s -- %[GRN]%s %[NC](%s)\n", __FUNCTION__,
** lex->content, g_token_type_str[lex->token_type]); usleep(1000);}
*/

typedef struct s_sh21	t_sh21;
typedef enum			e_token_type
{
	BEGIN,
	WORD,
	ASSIGNMENT_WORD,
	NAME,
	NEWLINE,
	IO_NUMBER,
	AND_IF,
	OR_IF,
	DSEMI,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESSANDDASH,
	GREATANDDASH,
	ANDGREAT,
	ANDGREATDASH,
	LESSGREAT,
	DLESSDASH,
	CLOBBER,
	EQUAL,
	If,
	Then,
	Else,
	Elif,
	Fi,
	Do,
	Time,
	Done,
	Case,
	Esac,
	While,
	Until,
	Function,
	Select,
	For,
	Lbrace,
	Rbrace,
	Bang,
	In,
	EOI,
	PIPE,
	AMPER,
	SEMI,
	LESS,
	GREATER,
	LPAREN,
	RPAREN,
	MAGICQ,
	BACKSLASH,
	DQUOTE,
	QUOTE,
	SPACE,
	TAB,
	ENDL,
	NOT_AN_OP,
	ERROR,
	IO_NUM_SPC
}						t_token_type;

typedef struct			s_lex
{
	struct s_lex	*next;
	t_token_type	token_type;
	char			*content;
}						t_lex;

t_lex					*g_err_lex;
t_lex					*g_end_of_input;

static const char		*g_token_type_str[] =
{
	"BEGIN",
	"WORD",
	"ASSIGN_WORD",
	"NAME",
	"NEWLINE",
	"IO_NUMBER",
	"&&",
	"||",
	";;",
	"<<",
	">>",
	"<&",
	">&",
	"<&-",
	">&-",
	"&>",
	"&>-",
	"<>",
	"<<-",
	">|",
	"=",
	"if",
	"then",
	"else",
	"elif",
	"fi",
	"do",
	"time",
	"done",
	"case",
	"esac",
	"while",
	"until",
	"function",
	"select",
	"for",
	"{",
	"}",
	"!",
	"in",
	"EOI",
	"|",
	"&",
	";",
	"<",
	">",
	"(",
	")",
	"`",
	"\\",
	"\"",
	"'",
	"<blank>",
	"<tab>",
	"END",
	"NOT_OP",
	"ERROR",
	"IO_NUM_SPC"
};

int						lexer(t_sh21 *sh21);
int						is_operator_part(char c, int stat);
int						is_redir_part(char c);
int						is_redir_token(t_token_type token_type);

int						assert_lex(t_lex *lex);
t_lex					*assignment_word(t_lex *lex);
t_lex					*case_clause(t_lex *lex);
t_lex					*case_clause_sequence(t_lex *lex);
t_lex					*case_command(t_lex *lex);
t_lex					*command(t_lex *lex);
t_lex					*compound_list(t_lex *lex);
t_lex					*elif_clause(t_lex *lex);
t_lex					*for_command(t_lex *lex);
t_lex					*function_def(t_lex *lex);
t_lex					*group_command(t_lex *lex);
t_lex					*if_command(t_lex *lex);
t_lex					*is_token(t_lex *lex, t_token_type token_type);
t_lex					*lex_create(t_token_type token_type, char *content);
t_lex					*list_root(t_lex *lex);
t_lex					*list0(t_lex *lex);
t_lex					*list1(t_lex *lex);
t_lex					*list_terminator(t_lex *lex);
t_lex					*newline_list(t_lex *lex);
t_lex					*pattern_list(t_lex *lex);
t_lex					*pipeline(t_lex *lex);
t_lex					*pipeline_command(t_lex *lex);
t_lex					*program(t_lex *lex);
t_lex					*redirection(t_lex *lex);
t_lex					*select_command(t_lex *lex);
t_lex					*simple_command(t_lex *lex);
t_lex					*shell_command(t_lex *lex);
t_lex					*simple_command_element(t_lex *lex);
t_lex					*simple_list(t_lex *lex);
t_lex					*simple_list1(t_lex *lex);
t_lex					*subshell(t_lex *lex);
t_lex					*timespec(t_lex *lex);
t_lex					*word_list(t_lex *lex);

t_token_type			get_operator_tok(char *str);
void					del_lex(void **lex);
void					print_lex_list(t_lex *elem);
void					word_rec(t_lex *lex);

typedef struct			s_lexa
{
	char			*str;
	char			*buffer;
	int				stat;
	char			prev;
	char			c;
	t_token_type	t;
	t_lex			*lex;
	int				oquote;
}						t_lexa;

static size_t g_lexa_buff_sz = 1024;

void					check_semi_stat(t_lexa *lexa);
void					on_quote(t_lexa *lexa);
void					on_blank(t_lexa *lexa);
void					on_operator_prev(t_lexa *lexa);
void					on_operator(t_lexa *lexa);
void					on_word(t_lexa *lexa);
void					lexfallback(t_lexa *lexa);
void					lexa_init(t_lexa *lexa, t_sh21 *sh21);
void					loop_word(t_lex *ptr);
void					word_recog(t_lexa *lexa);

#endif
