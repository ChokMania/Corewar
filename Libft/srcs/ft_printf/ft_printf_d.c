/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:34:31 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:09:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static __int64_t	ft_printf_d_get_arg(t_printf *p)
{
	__int64_t		ret;

	ret = 0;
	if (p->modifier == ft_printf_no_modifiers)
		ret = va_arg(p->ap, __int32_t);
	else if (p->modifier == ft_printf_h)
		ret = (__int16_t)va_arg(p->ap, __int32_t);
	else if (p->modifier == ft_printf_hh)
		ret = (__int8_t)va_arg(p->ap, __int32_t);
	else if (p->modifier == ft_printf_l)
		ret = va_arg(p->ap, long);
	else if (p->modifier == ft_printf_ll)
		ret = va_arg(p->ap, __int64_t);
	return (ret);
}

static t_printf		*ft_printf_d_precision(t_printf *p, __int64_t tmp)
{
	size_t		tmp2;
	char		*str;
	char		*buf;

	if (p->precision != -1 && !p->precision && !tmp)
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

static t_printf		*ft_printf_d_champ(t_printf *p, __int64_t nbr)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->champ != -1 && (size_t)p->champ > ft_strlen(p->conv_ret)
		&& (tmp = (size_t)p->champ - ft_strlen(p->conv_ret)))
	{
		if (((nbr < 0 && p->flags->zero) || (((p->flags->plus && nbr >= 0)
			|| p->flags->space) && p->flags->zero)) && p->precision == -1
			&& !p->flags->less)
			--tmp;
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

static t_printf		*ft_printf_d_flags(t_printf *p, __int64_t tmp)
{
	char		*str;
	char		*buf;

	buf = NULL;
	str = ft_strnew(1);
	if (tmp < 0 || (p->flags->plus && tmp >= 0))
	{
		str[0] = '+';
		if (tmp < 0)
			str[0] = '-';
		buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = buf;
	}
	else if (p->flags->space)
	{
		str[0] = ' ';
		buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = buf;
	}
	ft_strdel(&str);
	return (p);
}

t_printf			*ft_printf_d(t_printf *p)
{
	__int64_t		tmp;

	if (!(p->conv == ft_printf_decimal))
		return (p);
	if (!(p->conv_ret = ft_lltoabase_signless(
		(tmp = ft_printf_d_get_arg(p)), 10))
		&& (p->error = -1))
		return (p);
	p = ft_printf_d_precision(p, tmp);
	if (p->error)
		return (p);
	if (!(p->flags->zero && p->precision == -1 && !p->flags->less))
		p = ft_printf_d_flags(p, tmp);
	if (p->error)
		return (p);
	p = ft_printf_d_champ(p, tmp);
	if (p->error)
		return (p);
	if (p->flags->zero && p->precision == -1 && !p->flags->less)
		p = ft_printf_d_flags(p, tmp);
	if (p->error)
		return (p);
	ft_putstr_fd(p->conv_ret, p->fd);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
