/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:57 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:10:44 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static t_printf		*ft_printf_champ(t_printf *p)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->champ != -1 && (size_t)p->champ > 1
		&& (tmp = (size_t)p->champ - 1))
	{
		str = ft_strnew(tmp);
		if (p->flags->zero && (p->precision == -1 || !p->precision)
			&& !p->flags->less)
			str = ft_strfill(str, '0', tmp);
		else
			str = ft_strfill(str, ' ', tmp);
		if (p->flags->less)
			buf = ft_strjoin(p->conv_ret, str);
		else
			buf = ft_strjoin(str, p->conv_ret);
		if (!buf && (p->error = -1))
			return (p);
		ft_strdel(&p->conv_ret);
		ft_strdel(&str);
		p->conv_ret = buf;
	}
	return (p);
}

t_printf			*ft_printf_no_conv(t_printf *p)
{
	if (!((int)p->conv == (int)ft_printf_no_modifiers))
		return (p);
	if (!(p->conv_ret = ft_strnew(1))
		&& (p->error = -1))
		return (p);
	p->conv_ret[0] = p->tmpchar;
	p = ft_printf_champ(p);
	if (p->error)
		return (p);
	ft_putstr_fd(p->conv_ret, p->fd);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
