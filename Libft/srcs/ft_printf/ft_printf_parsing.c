/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:00:19 by judumay           #+#    #+#             */
/*   Updated: 2019/06/17 11:21:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

t_printf		*ft_printf_parsing(t_printf *p, const char *format)
{
	while (format[p->index]
		&& !(ft_strrchr("spdiouxXcf%", format[p->index])))
	{
		if (ft_strrchr("hlL", format[p->index]))
			ft_printf_get_modifier(p, format);
		else if (ft_strrchr("#0-+ ", format[p->index]))
			ft_printf_get_flag(p, format);
		else if (format[p->index] == '.')
			ft_printf_get_precision(p, format);
		else if ((format[p->index] != '0'
		&& ft_isdigit((__int32_t)format[p->index])))
			ft_printf_get_champ(p, format);
		else
			break ;
	}
	ft_printf_get_conv(p, format);
	if (!format[p->index] && (p->error = -1))
		return (p);
	if ((int)p->conv == (int)ft_printf_no_modifiers)
		p->tmpchar = format[p->index];
	++p->index;
	return (p);
}
