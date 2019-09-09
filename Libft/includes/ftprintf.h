/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:56:19 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:07:29 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef enum	e_printf_modifier
{
	ft_printf_no_modifiers
	, ft_printf_h
	, ft_printf_hh
	, ft_printf_l
	, ft_printf_ll
	, ft_printf_fl
}				t_modifier;

typedef enum	e_printf_conv
{
	no_input
	, ft_printf_char
	, ft_printf_decimal
	, ft_printf_octal
	, ft_printf_pointer
	, ft_printf_string
	, ft_printf_unsi
	, ft_printf_hexa
	, ft_printf_hexamaj
	, ft_printf_float
	, ft_printf_per
}				t_conv;

typedef struct	s_printf_flags
{
	__int32_t	hash;
	__int32_t	zero;
	__int32_t	less;
	__int32_t	space;
	__int32_t	plus;
}				t_printf_flags;

typedef struct	s_printf
{
	va_list			ap;
	__int32_t		error;
	__int32_t		index;
	__int32_t		ret;
	__int8_t		tmpchar;
	char			pad_0[3];
	char			*conv_ret;
	int				precision;
	int				fd;
	__int32_t		champ;
	t_printf_flags	*flags;
	t_modifier		modifier;
	t_conv			conv;
	struct s_printf	*(*tab_ptr[11])(struct s_printf *p);
}				t_printf;

int				ft_printf(char *format, ...);
int				ft_dprintf(int fd, char *format, ...);
int				ft_putdouble(double n, t_printf *p);
int				ldtoa_fill(double n, t_printf *p, long long value, int pe);
char			*ft_dtoa_printf(double n, t_printf *p, int t);
void			reset_t_printf(t_printf *p);
void			del_t_printf(t_printf *p);
void			ft_printf_display(t_printf *p, const char *format);
void			ft_printf_get_conv(t_printf *p, const char *format);
void			ft_printf_get_modifier(t_printf *p, const char *format);
void			ft_printf_get_flag(t_printf *p, const char *format);
void			ft_printf_get_precision(t_printf *p, const char *format);
void			ft_printf_get_champ(t_printf *p, const char *format);
t_printf		*ft_printf_parsing(t_printf *p, const char *format);
t_printf		*init_t_printf(t_printf *p);
t_printf		*ft_printf_conv(t_printf *p);
t_printf		*ft_printf_s(t_printf *p);
t_printf		*ft_printf_p(t_printf *p);
t_printf		*ft_printf_d(t_printf *p);
t_printf		*ft_printf_o(t_printf *p);
t_printf		*ft_printf_u(t_printf *p);
t_printf		*ft_printf_x(t_printf *p);
t_printf		*ft_printf_c(t_printf *p);
t_printf		*ft_printf_percent(t_printf *p);
t_printf		*ft_printf_no_conv(t_printf *p);
t_printf		*ft_printf_f(t_printf *p);
t_printf		*ft_printf_f_champ(t_printf *p, long double nbr);
t_printf		*ft_printf_f_flags(t_printf *p, long double tmp);

#endif
