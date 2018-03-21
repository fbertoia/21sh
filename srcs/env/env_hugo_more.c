/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_hugo_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:31:15 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/12 17:20:33 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void			ft_lstpush(t_list *lst, t_list *new)
{
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}

void			ft_lstqueue(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstpush(*lst, new);
}

char			**sh21_envchar(t_sh21 *sh21)
{
	char	**env;
	char	**begin;
	t_list	*current;

	if (!sh21)
		return (NULL);
	current = sh21->envl;
	env = malloc(sizeof(char *) * (ft_lstsize(sh21->envl) + 1));
	begin = env;
	while (current)
	{
		*env = ft_strdup(current->content);
		current = current->next;
		++env;
	}
	*env = NULL;
	return (begin);
}

size_t			compute(const char *n, const char *v, char **str, void *to_free)
{
	size_t	sz;

	free(to_free);
	to_free = NULL;
	sz = ft_strlen(n) + 1;
	v ? sz += ft_strlen(v) : (0);
	*str = ft_strnew(sz);
	ft_strcat(*str, n);
	ft_strcat(*str, "=");
	v ? ft_strcat(*str, v) : (0);
	return (sz);
}

char			*sh21_getenv(t_sh21 *sh21, const char *name)
{
	t_list	*current;
	char	*str;
	char	*where;

	current = sh21->envl;
	if (!sh21 || !name)
		return (NULL);
	while (current)
	{
		str = (char *)current->content;
		if (ft_strncmp(name, str, ft_strlen(name)) == 0
			&& *(str + ft_strlen(name)) == '=')
		{
			if ((where = ft_strchr(str, '=')))
				return (where + 1);
			else
				return (NULL);
		}
		current = current->next;
	}
	return (NULL);
}
