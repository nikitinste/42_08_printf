/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:04:16 by uhand             #+#    #+#             */
/*   Updated: 2019/04/20 19:39:55 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	long long int a;
	char res[200] = "%hdhi\n\0";

	a = 1738978937923982;
	// ret = printf(res, 123123, "abcde");
	// char res[200] = "%llld\n\0";
	ret = printf(res, a, "abcde");
	ft_putstr("\n-----> ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ret = ft_printf(res, a, "abcde");
	ft_putstr("\n-----> ");
	ft_putnbr(ret);
	ft_putchar('\n');
	return (0);
}
