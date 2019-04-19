/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:42:26 by uhand             #+#    #+#             */
/*   Updated: 2019/04/18 11:20:27 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ---------------------------- Flags parsing ---------------------------------|
*/

static int	check_flag(t_format *f, int i)
{
	if (!f->flags[i])
		f->flags[i]++;
	else
		return (0);
	return (1);
}

void	set_flags(t_printf *p, const char *format, t_format *f)
{
	while (P == ' ' || P == '#' || P == '0' || P == '-' || P == '+')
	{
		if (P == ' ')
			if (!check_flag(f, 0))
				return ;
		if (P == '#')
			if (!check_flag(f, 1))
				return ;
		if (P == '0')
			if (!check_flag(f, 2))
				return ;
		if (P == '-')
			if (!check_flag(f, 3))
				return ;
		if (P == '+')
			if (!check_flag(f, 4))
				return ;
		p->i++;
	}
}

/*
** ---------------------- Width & precision parsing ---------------------------|
*/

static void	get_wnp(t_printf *p, const char *format, va_list *ap, int *param)
{
	if (P != '*')
	{
		*param = ft_atoi(&P);
		while (P >= '0' && P <= '9')
			p->i++;
	}
	else
	{
		*param = va_arg(*ap, int);
		p->i++;
	}
}

void	set_wnp(t_printf *p, const char *format, t_format *f, va_list *ap)
{
	if (P != '.')
		get_wnp(p, format, ap, &f->width);
	if (P != '.')
		return ;
	p->i++;
	if (!((P >= '0' && P <= '9') || P == '*'))
	{
		f->precision = 0;
		return ;
	}
	get_wnp(p, format, ap, &f->precision);
}

/*
** ---------------------------- Length parsing --------------------------------|
*/

void	set_length(t_printf *p, const char *format, t_format *f)
{
	f->length[0] = P;
	if (P == 'l' || P == 'h')
		if (format[p->i] == format[p->i + 1])
		{
			f->length[1] = P;
			p->i++;
		}
	p->i++;
}
