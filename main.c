/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:04:16 by uhand             #+#    #+#             */
/*   Updated: 2019/06/12 17:39:46 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

# define INPUT "%#.hho", ULLONG_MAX
int		main(void)
{
	int		ret;
	char	*str;

	str = "abc";
	ret = ft_printf(INPUT);
	printf("\n%d\n\n", ret);
	ret = printf(INPUT);
	printf("\n%d\n", ret);
	return (0);
}

// ret = printf(res, 123123, "abcde");
// char res[200] = "%llld\n\0";
// "{% 03d}", 0
// "%10.5f", 0.3499
// "%-15.8lf", 38546.5849
// "%f|%-f|%+f|% f|%#f|%0f", -0., -0., -0., -0., -0., -0.
// "%f|%-f|%+f|% f|%#f|%0f", 0., 0., 0., 0., 0., 0.
// "%.8Lf", 12.847e451L
