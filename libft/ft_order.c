/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:02:22 by uhand             #+#    #+#             */
/*   Updated: 2018/12/24 20:02:24 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_order(unsigned long long num)
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
