/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:40:00 by uhand             #+#    #+#             */
/*   Updated: 2019/04/25 09:25:01 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_p(t_printf *p, t_format *f, va_list *ap)
{
	if (p || f || ap)
		return (0);
	return (1);
}

int		format_f(t_printf *p, t_format *f, va_list *ap)
{
	if (p || f || ap)
		return (0);
	return (1);
}

int		format_o(t_printf *p, t_format *f, va_list *ap)
{
	if (p || f || ap)
		return (0);
	return (1);
}

int		format_x(t_printf *p, t_format *f, va_list *ap)
{
	if (p || f || ap)
		return (0);
	return (1);
}
