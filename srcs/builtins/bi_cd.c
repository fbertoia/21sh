/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:45:16 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/15 14:43:49 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "ft_printf.h"
#include "libft.h"
#include "builtins.h"

int			change_oldpwd_pwd(char ***environ)
{
	char	buf[PATH_MAX];

	ft_setenv("OLDPWD", ft_getenv("PWD", environ), 1, environ);
	ft_setenv("PWD", getcwd(buf, PATH_MAX - 1), 1, environ);
	return (0);
}

int			bi_cd(int argc, char **argv, char ***environ)
{
	const char		*home = ft_getenv("HOME", environ);
	const char		*oldpwd = ft_getenv("OLDPWD", environ);

	if (argc < 2)
	{
		if (!chdir(home))
			return (change_oldpwd_pwd(environ));
		return (ft_error(-3, "cd"));
	}
	else if (ft_strequ(argv[1], "-"))
	{
		if (!chdir(oldpwd))
			return (change_oldpwd_pwd(environ));
		return (ft_error(-4, "cd"));
	}
	else if (!chdir(argv[1]))
		return (change_oldpwd_pwd(environ));
	else
		return (ft_error(errno, "cd"));
}
