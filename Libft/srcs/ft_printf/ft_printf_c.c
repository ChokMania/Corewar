/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:58:52 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:09:21 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static t_printf		*ft_printf_c_champ(t_printf *p)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->champ != -1 && (size_t)p->champ > 1 && (tmp = (size_t)p->champ - 1))
	{
		if (!(str = ft_strnew(tmp))
			&& (p->error = -1))
			return (p);
		if (p->flags->zero && !p->flags->less)
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

t_printf			*ft_printf_c(t_printf *p)
{
	__int8_t	arg;

	if (!(p->conv == ft_printf_char && p->modifier != ft_printf_l))
		return (p);
	arg = (__int8_t)va_arg(p->ap, __int32_t);
	if (!(p->conv_ret = ft_strnew(1))
		&& (p->error = -1))
		return (p);
	p->conv_ret[0] = arg;
	p = ft_printf_c_champ(p);
	if (p->error)
		return (p);
	if (!p->flags->less)
		ft_putstr_fd(p->conv_ret, p->fd);
	if (!arg && ++p->ret)
		ft_putchar_fd(arg, p->fd);
	if (p->flags->less)
		ft_putstr_fd(p->conv_ret, p->fd);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
