/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:17 by judumay           #+#    #+#             */
/*   Updated: 2019/08/22 14:10:24 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static double		ft_dabs(double n)
{
	return (n < 0 ? -n : n);
}

int					ft_putdouble(double n, t_printf *p)
{
	long long	tmp;
	long long	len;
	double		dec;
	long long	value;
	long long	pe;

	if (p->precision == -1)
		p->precision = 6;
	len = 1;
	tmp = (long long)(n < 0 ? -n : n);
	while (tmp && ++len)
		tmp /= 10;
	pe = p->precision + len + ((n < 0) ? 1 : 0);
	dec = ft_dabs(n);
	dec = (dec - (long long)(ft_dabs(n))) * ft_pow(10, p->precision + 1);
	dec = ((long long)dec % 10 > 4) ? dec / 10 + 1 : dec / 10;
	value = (long long)dec;
	pe = ldtoa_fill(n, p, value, pe);
	return (pe);
}

static long double	ft_printf_f_get_arg(t_printf *p)
{
	double	ret;

	ret = 0;
	if (p->modifier == ft_printf_no_modifiers)
		ret = va_arg(p->ap, double);
	else if (p->modifier == ft_printf_l)
		ret = va_arg(p->ap, double);
	else if (p->modifier == ft_printf_fl)
		ret = va_arg(p->ap, long double);
	return (ret);
}

t_printf			*ft_printf_f_suite(t_printf *p, double tmp, int i)
{
	if (p->error)
		return (p);
	if (!(p->flags->zero && !p->flags->less))
		if ((p = ft_printf_f_flags(p, tmp)) && p->error)
			return (p);
	if (i == 0 && !p->flags->hash)
	{
		while (p->conv_ret[i])
			p->conv_ret[i++] == '.' ? p->conv_ret[i - 1] = '\0' : 0;
		i = 0;
	}
	if ((p = ft_printf_f_champ(p, tmp)) && p->error)
		return (p);
	if (p->flags->zero && !p->flags->less)
		if ((p = ft_printf_f_flags(p, tmp)) && p->error)
			return (p);
	return (p);
}

t_printf			*ft_printf_f(t_printf *p)
{
	double		tmp;
	int			i;
	char		*tmpe;

	if ((i = 1) && !(p->conv == ft_printf_float))
		return (p);
	if ((tmp = ft_printf_f_get_arg(p)) && tmp != 0)
		i = ft_putdouble(tmp, p);
	else
	{
		p->precision < 0 ? p->precision = 6 : 0;
		p->conv_ret = ft_dtoa_printf(tmp, p, p->flags->hash);
	}
	if ((long long)tmp == 0 && p->conv_ret[0] == '.')
	{
		tmpe = ft_strjoin("0", p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = tmpe;
	}
	p = ft_printf_f_suite(p, tmp, i);
	if (p->error)
		return (p);
	ft_putstr_fd(p->conv_ret, p->fd);
	p->ret += ft_strlen(p->conv_ret);
	return (p);
}
