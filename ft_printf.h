/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:42:21 by uhand             #+#    #+#             */
/*   Updated: 2019/04/16 12:09:53 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_printf
{
	int		start;
	int		i;
	int		len;
	char	*str;
}				t_printf;

typedef struct	s_format
{
	int		width;
	int		precision;
	char	*flags;
	char	*length;
	char	type;
	//
}				t_format;

int		ft_printf(const char *format, ...);
int		join_f(const char *format, t_printf *p);
//size_t	ft_strlen(const char *s);
int		free_buf(char *buf);
int		addnchar(t_printf *p, char c, int n);
void	tformat_init(t_format *f);
#endif
