/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:56:29 by hfontain          #+#    #+#             */
/*   Updated: 2018/03/12 17:39:34 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int				controlc(t_input *input)
{
	goto_end_of_prompt(input);
	ft_exit(0, NULL);
	return (0);
}
