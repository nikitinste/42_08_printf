/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:38:58 by uhand             #+#    #+#             */
/*   Updated: 2019/05/22 20:27:06 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_double_rep(double n, t_fl_itoa *a)
{
	double	n_cpy;
	unsigned char		*sign;

	n_cpy = n;
	sign = (unsigned char*)&n_cpy;
	sign += 7;
	*sign = *sign >> 7;
	a->sign = *sign;
}
