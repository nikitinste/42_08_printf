/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:04:16 by uhand             #+#    #+#             */
/*   Updated: 2019/04/25 15:55:55 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

# define INPUT "%x", 0

int		main(void)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = ft_printf(INPUT);
	printf("\n%d\n\n", ret);
	ret = printf(INPUT);
	printf("\n%d\n", ret);
	return (0);
}

// ret = printf(res, 123123, "abcde");
// char res[200] = "%llld\n\0";
