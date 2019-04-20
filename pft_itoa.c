/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:45:16 by uhand             #+#    #+#             */
/*   Updated: 2019/04/20 15:46:45 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pft_order(unsigned long long num)
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

static void	set_string(char *str, unsigned long long num, int order, int dif)
{
	int		i;

	if (num == 0)
	{
		str[0] = '0';
		return ;
	}
	while (order > 0)
	{
		str[order + dif - 1] = (num % 10) + 48;
		num /= 10;
		order--;
	}
	i = 0;
	while (++i < dif)
		str[i] = '0';
}

static void	check_sig_n_nprec(int *dif, long long n, t_format *f)
{
	*dif = 0;
	if (f->len < f->precision)
	{
		*dif = f->precision - f->len;
		f->len = f->precision;
	}
	if (f->flags[4] || n < 0)
		f->len++;
}

char		*pft_itoa(long long n, t_format *f)
{
	char				*str;
	unsigned long long	num;
	int					dif;

	if (n < 0)
		num = (unsigned long long)(-n);
	else
		num = (unsigned long long)n;
	f->len = pft_order(num);
	check_sig_n_nprec(&dif, n, f);
	if (!(str = ft_strnew(f->len)))
		return (NULL);
	if (f->flags[4] || n < 0)
	{
		if (n < 0)
			str[0] = '-';
		else
			str[0] = '+';
		dif++;
	}
	else
		str[0] = '0';
	set_string(str, num, (f->len - dif), dif);
	return (str);
}
