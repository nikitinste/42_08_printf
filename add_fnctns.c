/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fnctns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:09:27 by uhand             #+#    #+#             */
/*   Updated: 2019/04/19 11:01:30 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		free_str(t_format *f)
{
	if (f->str != NULL)
		free(f->str);
	return (0);
}

int		free_buf(t_printf *p)
{
	if (p->str != NULL)
		free(p->str);
	return (-1);
}

void	tformat_init(t_format *f)
{
	int		i;

	f->width = -1;
	f->precision = -1;
	f->type = -1;
	i = -1;
	while (++i < 5)
		f->flags[i] = 0;
	f->length[0] = 0;
	f->length[1] = 0;
	f->len = 0;
	f->str = NULL;
}

void	tprintf_init(t_printf *p)
{
	p->start = 0;
	p->i = 0;
	p->len = 0;
	p->str = NULL;
	p->method_arr[0] = (method)&format_c;
	p->method_arr[1] = (method)&format_s;
	p->method_arr[2] = (method)&format_p;
	p->method_arr[3] = (method)&format_f;
	p->method_arr[4] = (method)&format_d;
	p->method_arr[5] = (method)&format_o;
	p->method_arr[6] = (method)&format_u;
	p->method_arr[7] = (method)&format_x;
	p->method_arr[8] = (method)&format_prcnt;
}
