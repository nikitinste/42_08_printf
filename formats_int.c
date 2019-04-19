/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:13:27 by uhand             #+#    #+#             */
/*   Updated: 2019/04/19 19:04:03 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	take_less(va_list *ap, int type)
{
	long long	arg;
	short int	arg_short;
	char		arg_char;

	if (type == 1)
	{
		arg_char = (char)va_arg(*ap, int);
		arg = (long long)arg_char;
	}
	else
	{
		arg_short = (short int)va_arg(*ap, int);
		arg = (long long)arg_short;
	}
	return (arg);
}

int		format_d(t_printf *p, t_format *f, va_list *ap)
{
	long long	arg;
	char		*str;
	int			order;

	if (f->length[0] != 0)
	{
		if (f->length[0] == 'l')
		{
			if (f->length[1] == 'l')
				arg = va_arg(*ap, long long);
			else
				arg = (long long)va_arg(*ap, long int);
		}
		if (f->length[0] == 'h')
		{
			if (f->length[1] == 'h')
				arg = take_less(ap, 1);
			else
				arg = take_less(ap, 2);		}
	}
	else
		arg = (long long)va_arg(*ap, int);
	str = pft_itoa(arg, &order);
	if (p)
		ft_putstr(str);
	return (1);
}
