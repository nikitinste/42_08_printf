/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:20:05 by uhand             #+#    #+#             */
/*   Updated: 2018/12/15 14:20:08 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_unsigned_itoa(unsigned long long n)
{
	char				*str;
	unsigned long long	num;
	int					order;

	num = n;
	order = ft_order(num);
	if (!(str = ft_strnew(order)))
		return (NULL);
	n = 0;
	set_string(&str, num, order, (int)n);
	return (str);
}
