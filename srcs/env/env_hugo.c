/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_hugo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:31:15 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:29:05 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int				sh21_addenv(t_sh21 *sh21, const char *n, const char *v)
{
	char	*str;
	size_t	sz;

	sz = ft_strlen(n) + 1;
	str = NULL;
	if (!sh21 || !v)
		return (-1);
	if (v)
		sz += ft_strlen(v);
	str = ft_strnew(sz);
	ft_strcat(str, n);
	ft_strcat(str, "=");
	v ? ft_strcat(str, v) : (0);
	ft_lstqueue(&(sh21->envl), ft_lstnew(str, 1 + sz));
	ft_strdel(&str);
	return (1);
}

int				sh21_setenv(t_sh21 *sh21, const char *n, const char *v, int o)
{
	t_list	*current;
	char	*str;
	size_t	sz;

	if (!sh21 || !n)
		return (0);
	current = sh21->envl;
	while (current)
	{
		if (ft_strncmp(n, (char *)current->content, ft_strlen(n)) == 0
			&& *((char *)current->content + ft_strlen(n)) == '=')
		{
			if (o)
			{
				sz = compute(n, v, &str, current->content);
				current->content = ft_strdup(str);
				current->content_size = sz;
				ft_strdel(&str);
				return (1);
			}
			return (0);
		}
		current = current->next;
	}
	return (sh21_addenv(sh21, n, v));
}

void			delete_str_list(void *data, size_t sz)
{
	ft_memdel(&data);
	(void)sz;
}

int				sh21_unsetenv(t_sh21 *sh21, const char *n)
{
	t_list	*current;
	t_list	*last;
	t_list	*next;

	if (!sh21 || !n)
		return (-1);
	last = NULL;
	current = sh21->envl;
	next = current->next;
	while (current)
	{
		if (ft_strncmp(n, (char *)current->content, ft_strlen(n)) == 0
			&& *((char *)current->content + ft_strlen(n)) == '=')
		{
			ft_lstdelone(&current, &delete_str_list);
			last ? (last->next = next) :
					(sh21->envl = next);
			return (1);
		}
		last = current;
		current = current->next;
		next = current->next;
	}
	return (0);
}

int				sh21_loadenv(t_sh21 *sh21, char **environ)
{
	while (*environ)
	{
		ft_lstqueue(&(sh21->envl),
			ft_lstnew(*environ, 1 + ft_strlen(*environ)));
		++environ;
	}
	return (1);
}
