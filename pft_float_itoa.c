/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_float_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:00:08 by uhand             #+#    #+#             */
/*   Updated: 2019/04/28 11:05:50 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char		*add_first_part_of_string(long double n, t_format *f, \
	t_fl_string *s, int i)
{
	if (!f->flags[3])
		left_side_starters(n, f, s, &i);
	else if (n < 0 || f->flags[4] || f->flags[0])
		add_sign_or_zero(f, s, n, &i);
	pft_strncpy(&f->str[i], s->w_part, s->w_len);
	pft_strncpy(&f->str[s->w_len + i], s->f_part, s->f_len);
	while (s->dif > 0)
	{
		f->str[f->len - s->dif] = ' ';
		s->dif--;
	}
	return (f->str);
}

char		*join_float_string(long double n, t_format *f, t_fl_string *s)
{
	int		i;

	i = 0;
	if (!(f->str = ft_strnew(f->len + 1)))
		return (free_float_parts(s));
	f->str[f->len] = '\0';
	if (s->dif <= 1)
	{
		if (s->dif == 1)
		{
			if (f->flags[3] && !(f->flags[4] || n < 0 || f->flags[0]))
				f->str[f->len - 1] = ' ';
			else
				add_sign_or_zero(f, s, n, &i);
		}
		pft_strncpy(&f->str[i], s->w_part, s->w_len);
		pft_strncpy(&f->str[s->w_len + i], s->f_part, (f->len - s->w_len - i));
		return (f->str);
	}
	else
		return (add_first_part_of_string(n, f, s, 0));
	free_float_parts(s);
	return (f->str);
}

void		set_float_string(char *str, unsigned long long num, int order, \
	int param)
{
	if (param)
		str[order] = '.';
	while (order > 0)
	{
		str[order - 1] = (num % 10) + 48;
		num /= 10;
		order--;
	}
}

char		*pft_zero_itoa(t_format *f, t_fl_itoa *a, t_fl_string *s)
{
	int		i;

	if (a->frc && !(f->precision > a->prec))
	{
		if (!(s->f_part = ft_strnew(a->frc_order + 1)))
			return (NULL);
		s->f_part[a->frc_order] = '\0';
		set_float_string(s->f_part, a->frc, a->frc_order, 0);
		f->len += a->frc_order;
		s->f_len = a->frc_order;
	}
	else if (a->frc && f->precision > a->prec)
		return (add_some_bagels(f, a, s));
	else
	{
		if (!(s->f_part = ft_strnew(f->precision + 1)))
			return (NULL);
		s->f_part[f->precision] = '\0';
		i = -1;
		while (++i < f->precision)
			s->f_part[i] = '0';
		f->len += f->precision;
		s->f_len = f->precision;
	}
	return (s->f_part);
}

char	*pft_whole_itoa(t_format *f, unsigned long long whole, char *str)
{
	int		dot;
	int		order;

	dot = 0;
	order = get_order(whole);
	f->len = order;
	if (f->precision > 0 || f->flags[1])
	{
		f->len++;
		dot = 1;
	}
	if (!(str = ft_strnew(f->len + 1)))
		return (NULL);
	str[f->len] = '\0';
	set_float_string(str, whole, order, dot);
	return(str);
}
