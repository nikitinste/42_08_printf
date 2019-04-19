/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:33:20 by uhand             #+#    #+#             */
/*   Updated: 2019/04/19 11:32:23 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	join_buf(t_printf *p, t_format *f)
{
	int		len;
	int		i;
	char	*buf;

	len = p->len + f->len;
	if (!(buf = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	buf[len] = '\0';
	i = -1;
	while (++i < p->len)
		buf[i] = p->str[i];
	i = -1;
	while ((p->len + ++i) < len)
		buf[p->len + i] = f->str[i];
	free(p->str);
	free(f->str);
	p->str = buf;
	p->len = len;
	return (1);
}

int		float_flags(t_printf *p, t_format *f)
{
	if (!join_buf(p, f))
		return (0);
	return (1);
}

int		int_flags(t_printf *p, t_format *f)
{
	if (!join_buf(p, f))
		return (0);
	return (1);
}

int		char_flags(t_printf *p, t_format *f)
{
	int		diff;
	char	c;

	if (f->width > f->len)
	{
		diff = f->width - f->len;
		c = ' ';
		if (f->flags[3])
		{
			if (!addnspaces(f, c, diff))
				return (0);
		}
		else
		{
			if (f->flags[2])
				c = '0';
			if (!addnchar(p, c, diff))
				return (0);
		}
	}
	if (!join_buf(p, f))
		return (0);
	return (1);
}
