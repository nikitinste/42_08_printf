/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:45:37 by uhand             #+#    #+#             */
/*   Updated: 2019/04/19 12:25:51 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_type(char c, t_format *f)
{
	if (c == 'c')
		f->type = 0;
	else if (c == 's')
		f->type = 1;
	else if (c == 'p')
		f->type = 2;
	else if (c == 'f')
		f->type = 3;
	else if (c == 'd')
		f->type = 4;
	else if (c == 'i')
		f->type = 4;
	else if (c == 'o')
		f->type = 5;
	else if (c == 'u')
		f->type = 6;
	else if (c == 'x')
		f->type = 7;
	else if (c == 'X')
		f->type = 7;
	else if (c == '%')
		f->type = 8;
}
