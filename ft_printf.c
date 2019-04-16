/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:41:59 by uhand             #+#    #+#             */
/*   Updated: 2019/04/16 11:48:10 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_format(va_list *ap, const char *format, t_printf *p)
{
	t_format	f;

	p->i++;
	if (format[p->i] == '%')
		return (addnchar(p, '%', 1));
	tformat_init(&f);
	//

	if (ap && format && p)
		return (1);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	p;

	p.start = 0;
	p.i = 0;
	p.len = 0;
	p.str = NULL;
	va_start(ap, format);
	while (format[p.i] != '\0')
	{
		while (format[p.i] != '%' && format[p.i] != '\0')
			p.i++;
		if (p.i != p.start)
			if (!join_f(format, &p))
				return (free_buf(p.str));
		if (!get_format(&ap, format, &p))
			return (free_buf(p.str));
		if (format[p.i] != '\0')
			p.i++;
		p.start = p.i;
	}
	write(1, p.str, p.len);
	free_buf(p.str);
	return (p.len);
}
