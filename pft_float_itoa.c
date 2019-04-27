/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_float_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:00:08 by uhand             #+#    #+#             */
/*   Updated: 2019/04/27 12:20:38 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join_float_string(long double n, t_format *f, t_fl_string *s)
{
	if (!(f->str = ft_strnew(f->len + 1)))
		return (free_float_parts(s));
	f->str[f->len] = '\0';
	if (!s->dif && n >= 0)
	{
		pft_strncpy(f->str, s->w_part, s->w_len);
		pft_strncpy(&f->str[s->w_len], s->f_part, (f->len - s->w_len));
		return (f->str);
	}
	else
	{
		return (f->str);
	}
	return (f->str);
}

static void	set_float_string(char *str, unsigned long long num, int order, \
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

char		*pft_zero_itoa(t_format *f, t_fl_itoa *a, char *str)
{
	int		i;

	if (a->frc)
	{
		if (!(str = ft_strnew(a->frc_order + 1)))
			return (NULL);
		str[a->frc_order] = '\0';
		set_float_string(str, a->frc, a->frc_order, 0);
		f->len += a->frc_order;
	}
	else
	{
		if (!(str = ft_strnew(f->precision + 1)))
			return (NULL);
		str[f->precision] = '\0';
		i = -1;
		while (++i < f->precision)
			str[i] = '0';
		f->len += f->precision;
	}
	return (str);
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
