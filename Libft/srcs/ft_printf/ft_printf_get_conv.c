/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:22 by judumay           #+#    #+#             */
/*   Updated: 2019/06/17 11:28:42 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static void		ft_pritnf_get_conv2(t_printf *p, const char *format)
{
	if (format[p->index] == 's')
		p->conv = ft_printf_string;
	else if (format[p->index] == 'u')
		p->conv = ft_printf_unsi;
	else if (format[p->index] == 'x')
		p->conv = ft_printf_hexa;
	else if (format[p->index] == 'X')
		p->conv = ft_printf_hexamaj;
	else if (format[p->index] == 'f')
		p->conv = ft_printf_float;
	else if (format[p->index] == '%')
		p->conv = ft_printf_per;
	else
		p->conv = no_input;
}

void			ft_printf_get_conv(t_printf *p, const char *format)
{
	if (format[p->index] == 'c')
		p->conv = ft_printf_char;
	else if (format[p->index] == 'd' || format[p->index] == 'i')
		p->conv = ft_printf_decimal;
	else if (format[p->index] == 'o')
		p->conv = ft_printf_octal;
	else if (format[p->index] == 'p')
		p->conv = ft_printf_pointer;
	else
		ft_pritnf_get_conv2(p, format);
}
