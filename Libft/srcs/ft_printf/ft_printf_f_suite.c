/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_suite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:12 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:59:13 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static t_printf		*ft_printf_f_flags2(t_printf *p, long double tmp)
{
	char		*str;
	char		*buf;

	buf = NULL;
	if ((str = ft_strnew(1)) && p->flags->plus && tmp >= 0)
	{
		if ((str[0] = '+') && (p->conv_ret[0] == '0' && tmp != 0
		&& (ft_strlen(p->conv_ret) == (size_t)p->champ)))
		{
			p->conv_ret[0] = '+';
			buf = ft_strdup(p->conv_ret);
		}
		else
			buf = ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = buf;
	}
	ft_strdel(&str);
	return (p);
}

t_printf			*ft_printf_f_flags(t_printf *p, long double tmp)
{
	int		i;
	char	*tmpe;

	tmpe = NULL;
	i = 0;
	p = ft_printf_f_flags2(p, tmp);
	if (p->flags->zero && tmp < 0)
	{
		while (p->conv_ret[i] && p->conv_ret[i] != '-')
			i++;
		p->conv_ret[i] = '0';
		p->conv_ret[0] = '-';
	}
	if (p->flags->zero && p->flags->plus && tmp > 0)
		p->conv_ret[0] = '+';
	if (tmp >= 0 && p->flags->space && !p->flags->plus)
	{
		tmpe = ft_strjoin(" ", p->conv_ret);
		ft_strdel(&p->conv_ret);
		p->conv_ret = tmpe;
	}
	return (p);
}

t_printf			*ft_printf_f_champ(t_printf *p, long double nbr)
{
	size_t		tmp;
	char		*str;
	char		*buf;

	if (p->champ != -1 && (size_t)p->champ > ft_strlen(p->conv_ret)
		&& (tmp = (size_t)p->champ - ft_strlen(p->conv_ret) + 1))
	{
		if ((((nbr < 0 && p->flags->zero) || (((p->flags->plus && nbr >= 0)
			|| p->flags->space) && p->flags->zero)) && !p->flags->less)
			|| p->conv_ret[0] == '-')
			--tmp;
		if (nbr >= 0)
			tmp--;
		str = ft_strnew(tmp);
		if (p->flags->zero && !p->flags->less)
			ft_strfill(str, '0', tmp);
		else
			ft_strfill(str, ' ', tmp);
		buf = p->flags->less ? ft_strjoin(p->conv_ret, str)
		: ft_strjoin(str, p->conv_ret);
		ft_strdel(&p->conv_ret);
		ft_strdel(&str);
		p->conv_ret = buf;
	}
	return (p);
}

int					ldtoa_fill_suite(double n, t_printf *p, int i, char *s)
{
	int		j;

	j = -1;
	(n < 0) ? s[0] = '-' : 0;
	ft_strdel(&p->conv_ret);
	p->conv_ret = s;
	p->precision = 0;
	while (p->conv_ret[p->precision] && p->precision <= i)
		p->precision++;
	if (p->precision == i)
		p->conv_ret[p->precision] = '\0';
	if (i > 16)
	{
		while (p->conv_ret[++j] && p->conv_ret[j] != '.')
			;
		while (p->conv_ret[++j])
			p->conv_ret[j] = '\0';
		p->precision--;
		ft_dtoa_printf(n, p, p->flags->hash);
		return (1);
	}
	return (0);
}

int					ldtoa_fill(double n, t_printf *p, long long value, int pe)
{
	long long		len;
	char			*s;
	int				i;

	i = p->precision;
	len = pe - 1 - p->precision;
	if (!(s = (char*)malloc(sizeof(char) * p->precision + len + 1)))
		return (0);
	s[len + p->precision + 1] = '\0';
	while (p->precision--)
	{
		s[len + p->precision + 1] = value % 10 + ((value % 10 < 10) ? '0' : 0);
		value /= 10;
	}
	s[len] = '.';
	value = (long long)(n < 0 ? -n : n);
	while (++p->precision < len)
	{
		s[len - p->precision - 1] = value % 10 + ((value % 10 < 10) ? '0' : 0);
		value /= 10;
	}
	if (ldtoa_fill_suite(n, p, i, s) == 1)
		ft_strdel(&s);
	return (i);
}
