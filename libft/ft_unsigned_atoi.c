/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:24:30 by uhand             #+#    #+#             */
/*   Updated: 2019/05/21 18:28:58 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		skip_starters(size_t *i, char *s, int *sign)
{
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		*i = *i + 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign = -1;
		*i = *i + 1;
	}
	while (s[*i] == '0')
		*i = *i + 1;
}

static void		calc_result(size_t i, char *s, unsigned long long *res, \
	size_t len)
{
	unsigned long long	prev_res;
	long long			order;

	order = 1;
	while (len > 0)
	{
		prev_res = *res;
		*res = *res + ((s[i + len - 1] - 48) * order);
		order *= 10;
		if (*res < prev_res)
		{
			*res = 0;
			return ;
		}
		len--;
	}
}

static void		check_digits(size_t i, char *s, unsigned long long *res)
{
	size_t		len;

	len = 0;
	while (ft_isdigit(s[i + len]))
		len++;
	calc_result(i, s, res, len);
}

unsigned int	ft_unsigned_atoi(const char *str)
{
	size_t				i;
	char				*s;
	unsigned long long	res;
	int					sign;

	i = 0;
	s = (char*)str;
	res = 0;
	sign = 1;
	if (ft_strlen(str) == 0)
		return (0);
	skip_starters(&i, s, &sign);
	if (!(ft_isdigit(s[i])))
		return (0);
	check_digits(i, s, &res);
	return ((unsigned int)res * sign);
}
