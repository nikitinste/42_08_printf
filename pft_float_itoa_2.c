/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_float_itoa_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 09:50:06 by uhand             #+#    #+#             */
/*   Updated: 2019/04/28 11:06:28 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*free_float_parts(t_fl_string *s)
{
	if (s->w_part != NULL)
		free(s->w_part);
	if (s->w_part != NULL)
		free(s->f_part);
	return (NULL);
}

int 		get_order(unsigned long long num)
{
	int		order;

	if (num == 0)
		return (1);
	order = 0;
	while (num > 0)
	{
		num /= 10;
		order++;
	}
	return (order);
}

void	add_sign_or_zero(t_format *f, t_fl_string *s, long double n, int *i)
{
	if (n < 0)
		f->str[*i] = '-';
	else if (f->flags[4])
		f->str[*i] = '+';
	else if (f->flags[0])
		f->str[*i] = ' ';
	else if (f->flags[2])
		f->str[*i] = '0';
	else
		f->str[*i] = ' ';
	*i += 1;
	s->dif--;
}

char *add_some_bagels(t_format *f, t_fl_itoa *a, t_fl_string *s)
{
	int		i;

	if (!(s->f_part = ft_strnew(f->precision + 1)))
		return (NULL);
	s->f_part[f->precision] = '\0';
	set_float_string(s->f_part, a->frc, a->frc_order, 0);
	i = 0;
	while ((a->frc_order + i) < f->precision)
	{
		s->f_part[a->frc_order + i] = '0';
		i++;
	}
	f->len += f->precision;
	s->f_len = f->precision;
	return (s->f_part);
}

void	left_side_starters(long double n, t_format *f, t_fl_string *s, int *i)
{
	if (!f->flags[2])
	{
		while (*i < (s->dif - 1))
		{
			f->str[*i] = ' ';
			*i += 1;
		}
		s->dif = 0;
		add_sign_or_zero(f, s, n, i);
	}
	else
	{
		add_sign_or_zero(f, s, n, i);
		while (*i < (s->dif))
		{
			f->str[*i] = '0';
			*i += 1;
		}
	}
}
