/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:40 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:59:41 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

void			ft_printf_get_precision(t_printf *p, const char *format)
{
	__int32_t	i;
	__int32_t	tmp;
	__int8_t	tmp_intmax_buffer;

	i = 0;
	++p->index;
	tmp = ft_atoi(&format[p->index]);
	while (format[p->index] == '0')
		++p->index;
	tmp_intmax_buffer = format[p->index];
	while (ft_isdigit(format[p->index + i]) && i < 11)
		++i;
	if (!ft_isdigit(format[p->index]) && !(p->precision = 0))
		return ;
	while (ft_isdigit(format[p->index]))
		++p->index;
	if (tmp < 0 || i > 11 || (i == 10 && tmp_intmax_buffer > '2'))
		return ;
	p->precision = tmp;
}
