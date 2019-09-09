/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:00:43 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:11:53 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static __uint64_t	ft_printf_x_get_arg(t_printf *p)
{
	__uint64_t	ret;

	ret = 0;
	if (p->modifier == ft_printf_no_modifiers)
		ret = va_arg(p->ap, __uint32_t);
	else if (p->modifier == ft_printf_h)
		ret = (__uint16_t)va_arg(p->ap, __uint32_t);
	else if (p->modifier == ft_printf_hh)
		ret = (__uint8_t)va_arg(p->ap, __uint32_t);
	else if (p->modifier == ft_printf_l)
		ret = va_arg(p->ap, unsigned long);
	else if (p->modifier == ft_printf_ll)
		ret = va_arg(p->ap, __uint64_t);
	return (ret);
}

static t_printf		*ft_printf_x_precision(t_printf *p, __uint64_t tmp)
{
	size_t		tmp2;
	char		*str;
	char		*buf;

	if (p->precision == 0 && !tmp)
	{
		str = ft_strnew(0);
		ft_strdel(&p->conv_ret);
		p->conv_ret = str;
	}
	else if (p->precision != -1 && (size_t)p->precision > ft_strlen(p->conv_ret)
		&& (tmp2 = (size_t)p->precision - ft_strlen(p->conv_ret)))
	{
		if (!(str = ft_strnew(tmp2))
			&& (p->error = -1))
			return (p);
		str = ft_strfill(str, '0', tmp2);
		buf = ft_strjoin(str, p->conv_ret);
		if (!buf && (p->error = -1))
			return (p);
		ft_strdel(&p->conv_ret);
		ft_strdel(&str);
		p->conv_ret = buf;
	}
	return (p);
}

static t_printf		*ft_printf_x_champ(t_printf *p)
{
	int			tmp;
	char		*str;
	char		*buf;

	if (p->champ != -1 && (size_t)p->champ > ft_strlen(p->conv_ret)
		&& (tmp = (size_t)p->champ - ft_strlen(p->conv_ret)))
	{
		if (p->flags->zero && p->precision == -1 && !p->flags->less
			&& p->flags->hash && p->conv_ret[0] != '0')
			tmp = tmp < 2 ? 0 : tmp - 2;
		str = ft_strnew(tmp);
		if (p->flags->zero && p->precision == -1 && !p->flags->less)
			str = ft_strfill(str, '0', tmp);
		else
			str = ft_strfill(str, ' ', tmp);
		if (p->flags->less)
			buf = ft_strjoin(p->conv_ret, str);
		else
			buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		ft_strdel(&str);
		p->conv_ret = buf;
	}
	return (p);
}

static t_printf		*ft_printf_x_flags(t_printf *p, __uint64_t tmp)
{
	char		*str;
	char		*buf;

	str = NULL;
	buf = NULL;
	if (p->flags->hash && tmp)
	{
		if ((!(str = ft_strnew(2)))
			&& (p->error = -1))
			return (p);
		str[0] = '0';
		str[1] = 'x';
		buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = buf;
		ft_strdel(&str);
	}
	return (p);
}

t_printf			*ft_printf_x(t_printf *p)
{
	__uint64_t	tmp;

	if (!(p->conv == ft_printf_hexa || p->conv == ft_printf_hexamaj))
		return (p);
	p->conv_ret = ft_lltoabase_unsigned(
		(tmp = ft_printf_x_get_arg(p)), 16);
	p = ft_printf_x_precision(p, tmp);
	if (p->error)
		return (p);
	if (!(p->flags->zero && p->precision == -1 && !p->flags->less))
		p = ft_printf_x_flags(p, tmp);
	if (p->error)
		return (p);
	p = ft_printf_x_champ(p);
	if (p->error)
		return (p);
	if (p->flags->zero && p->precision == -1 && !p->flags->less)
		p = ft_printf_x_flags(p, tmp);
	if (p->error)
		return (p);
	if (p->conv == ft_printf_hexamaj)
		p->conv_ret = ft_strtoupper_leakless(p->conv_ret);
	ft_putstr_fd(p->conv_ret, p->fd);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
