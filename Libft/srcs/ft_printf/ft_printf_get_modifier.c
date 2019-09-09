/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_modifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:10:50 by judumay           #+#    #+#             */
/*   Updated: 2019/06/17 11:24:21 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

void			ft_printf_get_modifier(t_printf *p, const char *format)
{
	if (format[p->index] == 'h')
	{
		if (p->modifier == ft_printf_h)
			p->modifier = ft_printf_hh;
		else if (p->modifier < ft_printf_h)
			p->modifier = ft_printf_h;
	}
	if (format[p->index] == 'l')
	{
		if (p->modifier == ft_printf_l)
			p->modifier = ft_printf_ll;
		else if (p->modifier < ft_printf_l)
			p->modifier = ft_printf_l;
	}
	if (format[p->index] == 'L')
		p->modifier = ft_printf_fl;
	++p->index;
}
