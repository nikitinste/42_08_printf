/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:52:18 by uhand             #+#    #+#             */
/*   Updated: 2019/04/28 14:56:26 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	put_ordr(int order)
{
	unsigned long long res;

	res = 1;
	while (order > 0)
	{
		res *= 10;
		order--;
	}
	return (res);
}

static char					*get_float_string(long double n, t_format *f, \
	t_fl_itoa *a)
{
	t_fl_string			s;

	s.w_part = NULL;
	s.f_part = NULL;
	s.dif = 0;
	if (!(s.w_part = pft_whole_itoa(f, a->whl, s.w_part)))
		return (NULL);
	s.w_len = f->len;
	if (!(s.f_part = pft_zero_itoa(f, a, &s)))
	{
		free(s.w_part);
		return (NULL);
	}
	if (f->width > f->len)
	{
		s.dif = f->width - f->len;
		f->len = f->width;
	}
	else if (f->flags[4] || f->flags[0] || n < 0)
	{
		f->len++;
		s.dif++;
	}
	return (join_float_string(n, f, &s));
}

static void					get_round(t_fl_itoa *a)
{
	if ((a->frc % 10) >= 5)
	{
		if (get_order(a->frc + 10) > a->frc_order)
			a->whl++;
		a->frc = ((a->frc + 10) / 10);
	}
	else
		a->frc /= 10;
}

static char					*pft_float_itoa(long double n, t_format *f)
{
	t_fl_itoa			a;

	if (f->precision == -1)
		f->precision = 6;
	a.prec = f->precision;
	if (f->precision > 18)
		a.prec = 18;
	if (n < 0)
		a.num = (-n);
	else
		a.num = n;
	a.whl = (unsigned long long)a.num;
	a.frc = (unsigned long long)((a.num - a.whl) * put_ordr(a.prec + 1));
	a.frc_order = get_order(a.frc);
	if (a.frc && a.frc_order > 1)
		get_round(&a);
	else if (a.frc && a.frc >= 5)
		a.whl++;
	a.frc_order--;
	return (get_float_string(n, f, &a));
}

int							format_f(t_printf *p, t_format *f, va_list *ap)
{
	long double			arg;

	if (f->length[0] != 0 && f->length[0] == 'L')
		arg = va_arg(*ap, long double);
	else
		arg = (long double)va_arg(*ap, double);
	if (!(f->str = pft_float_itoa(arg, f)))
		return (0);
	if (!join_buf(p, f))
		return (0);
	return (1);
}
