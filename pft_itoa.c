/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:45:16 by uhand             #+#    #+#             */
/*   Updated: 2019/04/19 19:00:29 by uhand            ###   ########.fr       */
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

static void	set_string(char **str, unsigned long long num, int order, int i)
{
	if (num == 0)
	{
		str[0][0] = '0';
		return ;
	}
	while (order > 0)
	{
		str[0][order + i - 1] = (num % 10) + 48;
		num /= 10;
		order--;
	}
}

char		*pft_itoa(long long n, int *order)
{
	char				*str;
	unsigned long long	num;

	if (n < 0)
		num = (unsigned long long)(-n);
	else
		num = (unsigned long long)n;
	*order = pft_order(num);
	if (n < 0)
		*order += 1;
	if (!(str = ft_strnew(*order)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		*order -= 1;
		n = 1;
	}
	else
		n = 0;
	set_string(&str, num, *order, (int)n);
	return (str);
}
