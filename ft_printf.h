/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:42:21 by uhand             #+#    #+#             */
/*   Updated: 2019/04/19 12:11:38 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define P format[p->i]

typedef struct s_printf	t_printf;
typedef struct s_format	t_format;
typedef int (*method)(t_printf *p, t_format *f, void *data);

/*
** Current format's params: f
*/

struct	s_format
{
	int		width;
	int		precision;
	int		type;
	int		len;
	char	flags[5];
	char	length[2];
	char	*str;
};

/*
** Operational format string's params: p
*/

struct	s_printf
{
	int		start;
	int		i;
	int		len;
	char	*str;
	method	method_arr[9];
};

int		ft_printf(const char *format, ...);
void	tprintf_init(t_printf *p);
int		join_f(const char *format, t_printf *p);
int		free_buf(t_printf *p);
int		free_str(t_format *f);
int		addnchar(t_printf *p, char c, int n);
void	pft_strncpy(char *dst, const char *src, size_t len);
void	tformat_init(t_format *f);
int		addnspaces(t_format *f, char c, int n);

void	set_flags(t_printf *p, const char *format, t_format *f);
void	set_wnp(t_printf *p, const char *format, t_format *f, va_list *ap);
void	set_length(t_printf *p, const char *format, t_format *f);
void	set_type(char c, t_format *f);
int		char_flags(t_printf *p, t_format *f);
int		int_flags(t_printf *p, t_format *f);
int		float_flags(t_printf *p, t_format *f);

int		format_c(t_printf *p, t_format *f, va_list *ap);
int		format_s(t_printf *p, t_format *f, va_list *ap);
int		format_p(t_printf *p, t_format *f, va_list *ap);
int		format_f(t_printf *p, t_format *f, va_list *ap);
int		format_d(t_printf *p, t_format *f, va_list *ap);
int		format_o(t_printf *p, t_format *f, va_list *ap);
int		format_u(t_printf *p, t_format *f, va_list *ap);
int		format_x(t_printf *p, t_format *f, va_list *ap);
int		format_prcnt(t_printf *p, t_format *f, va_list *ap);
#endif
