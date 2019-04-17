/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:45:37 by uhand             #+#    #+#             */
/*   Updated: 2019/04/17 17:59:00 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_type(char c, t_printf *p, t_format *f)
{
	if (c == 'c')
		f->type = 0;
	if (c == 's')
		f->type = 1;
	if (c == 'p')
		f->type = 2;
	if (c == 'f')
		f->type = 3;
	if (c == 'd')
		f->type = 4;
	if (c == 'i')
		f->type = 4;
	if (c == 'o')
		f->type = 5;
	if (c == 'u')
		f->type = 6;
	if (c == 'x')
		f->type = 7;
	if (c == 'X')
		f->type = 7;
	p->i++;
}
