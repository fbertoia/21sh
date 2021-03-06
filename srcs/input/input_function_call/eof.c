/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:28:22 by fbertoia          #+#    #+#             */
/*   Updated: 2018/02/20 13:28:24 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		sh21_eof(t_input *input)
{
	if (!*input->buff)
		ft_exit(0, NULL);
	delete_forw(input);
	return (0);
}
