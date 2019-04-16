/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fnctns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:09:27 by uhand             #+#    #+#             */
/*   Updated: 2019/04/16 11:29:41 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		free_buf(char *buf)
{
	if (buf != NULL)
		free(buf);
	return (-1);
}

void	tformat_init(t_format *f)
{
	f->width = -1;
	f->precision = -1;
	f->flags = NULL;
	f->length = NULL;
	f->type = -1;
}
