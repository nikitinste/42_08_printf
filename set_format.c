/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:42:26 by uhand             #+#    #+#             */
/*   Updated: 2019/04/17 17:58:57 by uhand            ###   ########.fr       */
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
	while (POS == ' ' || POS == '#' || POS == '0' || POS == '-' || POS == '+')
	{
		if (POS == ' ')
			if (!check_flag(f, 0))
				return ;
		if (POS == '#')
			if (!check_flag(f, 1))
				return ;
		if (POS == '0')
			if (!check_flag(f, 2))
				return ;
		if (POS == '-')
			if (!check_flag(f, 3))
				return ;
		if (POS == '+')
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
	if (POS != '*')
	{
		*param = ft_atoi(&POS);
		while (POS >= '0' && POS <= '9')
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
	if (POS != '.')
		get_wnp(p, format, ap, &f->width);
	if (POS != '.')
		return ;
	p->i++;
	if (!((POS >= '0' && POS <= '9') || POS == '*'))
		return ;
	get_wnp(p, format, ap, &f->precision);
}

/*
** ---------------------------- Length parsing --------------------------------|
*/

void	set_length(t_printf *p, const char *format, t_format *f)
{
	f->length[0] = POS;
	if (POS == 'l' || POS == 'h')
		if (format[p->i] == format[p->i + 1])
		{
			f->length[1] = POS;
			p->i++;
		}
	p->i++;
}
