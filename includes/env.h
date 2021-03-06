/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:56:29 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/15 15:54:31 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define HASH_SIZE 1 << 16

typedef struct			s_hash_bin
{
	struct s_hash_bin	*next;
	char				*path;
}						t_hash_bin;

typedef struct			s_env
{
	char				**orig_env;
	char				**local_var;
	char				**env_cpy;
	t_hash_bin			hash_table[HASH_SIZE];
}						t_env;

int						env_usage(char c, int option);

#endif
