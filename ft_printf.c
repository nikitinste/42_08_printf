/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:41:59 by uhand             #+#    #+#             */
/*   Updated: 2019/04/17 17:33:57 by uhand            ###   ########.fr       */
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
	if (POS == ' ' || POS == '#' || POS == '0' || POS == '-' || POS == '+')
		set_flags(p, format, &f);
	if (POS == '.' || (POS >= '0' && POS <= '9') || POS == '*')
		set_wnp(p, format, &f, ap);
	if (POS == 'h' || POS == 'l' || POS == 'L')
		set_length(p, format, &f);
	if (POS == 'c' || POS == 's' || POS == 'p' || POS == 'f' || POS == 'd' \
		|| POS == 'i' || POS == 'o' || POS == 'u' || POS == 'x' || POS == 'X')
			set_type(POS, p, &f);
	else if (format[p->i] == '%')
		return (addnchar(p, '%', 1));
	else
		return (1);
	return (p->method_arr[f.type](p, &f, ap));
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	p;

	tprintf_init(&p);
	va_start(ap, format);
	while (format[p.i] != '\0')
	{
		while (format[p.i] != '%' && format[p.i] != '\0')
			p.i++;
		if (p.i != p.start)
			if (!join_f(format, &p))
				return (free_buf(&p));
		if (!get_format(&ap, format, &p))
			return (free_buf(&p));
		if (format[p.i] != '\0')
			p.i++;
		p.start = p.i;
	}
	write(1, p.str, p.len);
	free_buf(&p);
	return (p.len);
}
