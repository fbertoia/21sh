# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 10:28:00 by fbertoia          #+#    #+#              #
#    Updated: 2018/03/21 10:28:10 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CC = gcc
INCLUDES_DIR = includes
CFLAGS = -Wall -Wextra -Werror -O3
IFLAGS = -I$(INCLUDES_DIR)
INCLUDES = sh21.h ft_printf.h error_message.h libft.h input.h lexer.h ast.h env.h
VPATH=	./includes:./libft:./objs:./srcs:./srcs/builtins:\
		./srcs/env:./srcs/input:./srcs/input/cursor:\
		./srcs/input/history:./srcs/input/input_function_call:\
		./srcs/input/utils:./srcs/lexer_parser_ast:\
		./srcs/lexer_parser_ast/ast:./srcs/lexer_parser_ast/ast/tree_build:\
		./srcs/lexer_parser_ast/ast/tree_exec:./srcs/lexer_parser_ast/lexer:\
		./srcs/lexer_parser_ast/parser:./srcs/lexer_parser_ast/parser/parser_funcs:\
		./srcs/sh21:./srcs/sh21/del:./srcs/sh21/errors:\
		./srcs/sh21/print:./srcs/sh21/signal

SRCS =	bi_cd.c bi_echo.c bi_env.c bi_exit.c bi_export.c bi_hash.c bi_setenv.c \
		bi_unset.c bi_unsetenv.c ft_getenv.c ft_putenv.c ft_setenv.c ft_unsetenv.c \
		hash_table_builtins.c env_hugo.c env_hugo_more.c cursor.c cut.c add_history.c \
		init_history.c arrow_down.c arrow_left.c arrow_right.c arrow_up.c beg_line.c \
		clear_screen.c controlc.c copypaste.c delete_back.c delete_forw.c end_line.c \
		eof.c line_down.c line_up.c newline.c word_beg.c word_end.c write_char.c \
		clear_command.c display_input.c input_call_function.c input_get.c input_init.c \
		my_putchar.c opentty.c exec_tree.c add_str.c ast_create_node.c ast_redir_function.c \
		find_var.c format_word.c free_node.c heredoc_node.c restore_fd.c skip_var.c \
		split_args.c func_amper.c func_and_if.c func_assignment_word.c func_backslash.c \
		func_bang.c func_case.c func_do.c func_dollar.c func_done.c func_dquote.c \
		func_dsemi.c func_elif.c func_else.c func_endl.c func_eoi.c func_equal.c \
		func_esac.c func_fi.c func_for.c func_function.c func_heredoc.c func_if.c \
		func_in.c func_io_number.c func_lbrace.c func_lparen.c func_magicq.c \
		func_name.c func_newline.c func_or_if.c func_pipe.c func_quote.c func_rbrace.c \
		func_redirection.c func_rparen.c func_select.c func_semi.c func_space.c \
		func_tab.c func_then.c func_time.c func_until.c func_while.c func_word.c \
		lexer.c lexer_token_recognize.c lexutils.c lexutils_more.c parser.c \
		assert_lex.c assignement_word.c case_clause.c case_clause_sequence.c \
		case_command.c command.c compound_list.c elif_clause.c for_command.c \
		function_def.c group_command.c if_command.c is_token.c list.c list0.c \
		list1.c list_terminator.c newline_list.c pattern_list.c pipeline.c \
		pipeline_command.c program.c redirection.c select_command.c shell_command.c \
		simple_command.c simple_command_element.c simple_list.c simple_list1.c \
		subshell.c timespec.c word_list.c main.c del_ast.c del_env.c del_hash.c \
		del_history.c del_input.c del_lex.c del_redir.c del_sh21.c errors.c \
		input_piped_script.c env_usage.c print_env.c print_history.c print_lex.c \
		set_debug.c set_sh21.c sh21_exec.c signal.c
LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a
OBJS = $(SRCS:.c=.o)
OBJS_PATH = ./objs
OBJS_WITH_PATH = $(OBJS:%.o=objs/%.o)
MAKEFILE = Makefile

all: library $(NAME)

library:
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB) $(INCLUDES) $(MAKEFILE)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_WITH_PATH) $(LIB)  -ltermcap -o $@
	@printf "\n[$(NAME)] \033[1;32m===%s completed===\033[0m\n" "$(NAME)"

%.o: %.c $(INCLUDES) $(MAKEFILE)
	@printf "\r\33[2K[$(NAME)] \033[1;33mBuilding %s\033[0m" "$(NAME)"
	@$(CC) -o $(OBJS_PATH)/$@ -c $(CFLAGS) $(IFLAGS) $<

clean:
	@printf "[$(NAME)] \033[1;31mDeleting %s objects\033[0m\n" "$(NAME)"
	@rm -f $(OBJS_WITH_PATH)
	@make -C ./libft clean

fclean: clean
	@printf "[$(NAME)] \033[1;31mDeleting %s project \033[0m\n" "$(NAME)"
	@rm -f $(NAME)
	@printf "[$(NAME)] \033[1;31mDeleting Libft library\033[0m\n"
	@rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re library printf
