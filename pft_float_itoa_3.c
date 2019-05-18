/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_float_itoa_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:29:13 by uhand             #+#    #+#             */
/*   Updated: 2019/05/18 16:32:47 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_first_part_of_string(long double n, t_format *f, \
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
