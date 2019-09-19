/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:04 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:07:42 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

void		ft_printf_display(t_printf *p, const char *format)
{
	size_t		buf;

	while (format[p->index])
	{
		buf = ft_strclen(&format[p->index], '%');
		write(p->fd, &format[p->index], buf);
		p->ret += buf;
		p->index += buf;
		if (format[p->index] == '%')
		{
			if (!format[++p->index])
				break ;
			p = ft_printf_parsing(p, format);
			if (p->error)
				break ;
			p = ft_printf_conv(p);
			if (p->error)
				break ;
			reset_t_printf(p);
		}
	}
}
