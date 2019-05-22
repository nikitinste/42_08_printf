/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:52:18 by uhand             #+#    #+#             */
/*   Updated: 2019/05/22 20:19:26 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long			put_ordr(int order)
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

static char					*get_float_string(t_format *f, t_fl_itoa *a)
{
	t_fl_string			s;

	s.w_part = NULL;
	s.f_part = NULL;
	s.dif = 0;
	if (!(s.w_part = pft_whole_itoa(f, a->whl, &s)))
		return (NULL);
	f->len = s.w_len;
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
	else if (f->flags[4] || f->flags[0] || a->sign == 1)
	{
		f->len++;
		s.dif++;
	}
	return (join_float_string(f, &s, a));
}

static void					get_round(t_fl_itoa *a)
{
	if (a->frc_order == a->prec + 1)
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
	else
	{
		if ((a->frc % 10) >= 5)
		{
			a->frc = ((a->frc + 10) / 10);
			a->frc_order++;
		}
		else
			a->frc /= 10;
	}
}

static char					*pft_float_itoa(long double n, t_format *f)
{
	t_fl_itoa			a;

	a.arg = n;
	if (n < 0)
		a.num = (-n);
	else
		a.num = n;
	get_double_rep(n, &a);
	if (f->precision < 0)
		f->precision = 6;
	a.prec = f->precision;
	a.whl = (unsigned long long)a.num;
	if (f->precision > 18)
		return (get_long_precision(f, &a));
	a.frc = (unsigned long long)((a.num - a.whl) * put_ordr(a.prec + 1));
	a.frc_order = get_order(a.frc);
	if (a.frc && (a.frc_order > 1 || (a.frc_order == 1 && a.prec > 1)))
		get_round(&a);
	else if (a.frc && a.frc >= 5 && (a.frc_order == a.prec + 1))
		a.whl++;
	a.frc_order--;
	return (get_float_string(f, &a));
}

int							format_f(t_printf *p, t_format *f, va_list *ap)
{
	double				arg;

	if (f->length[0] != 0 && f->length[0] == 'L')
		arg = (double)va_arg(*ap, long double);
	else
		arg = va_arg(*ap, double);
	if (arg != arg)
	{
		f->len = 3;
		if (!(f->str = (char*)malloc(sizeof(char) * (f->len + 1))))
			return (0);
		f->str[f->len] = '\0';
		pft_strncpy(f->str, "nan", f->len);
		return (char_flags(p, f));
	}
	else if (!(f->str = pft_float_itoa(arg, f)))
		return (0);
	if (!join_buf(p, f))
		return (0);
	return (1);
}
