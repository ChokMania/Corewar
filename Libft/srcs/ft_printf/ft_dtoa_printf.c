/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:58:47 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:58:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>
#include <stdlib.h>

static int		handle_no_number_after_decimal(int prec, char **s)
{
	char		*s_tmp;
	int			i;

	i = 0;
	if (!(s_tmp = (char *)malloc(sizeof(char) * (prec + 1))))
		return (1);
	while (prec--)
		s_tmp[i++] = '0';
	s_tmp[i] = '\0';
	ft_strcat(*s, s_tmp);
	ft_strdel(&s_tmp);
	return (0);
}

static int		precision_smaller_than_10(double n, int prec, char **s)
{
	char		*s_tmp;
	int			prec_tmp;
	int			i;

	i = 0;
	n = n * ft_pow(10, prec);
	prec_tmp = prec - ft_longlen(n);
	if (!(s_tmp = (char *)malloc(sizeof(char) * (prec_tmp + 1))))
		return (1);
	while (prec_tmp--)
		s_tmp[i++] = '0';
	s_tmp[i] = '\0';
	if ((long)((n - (long)n) * 10) > 4)
		n += 1;
	ft_strcat(*s, s_tmp);
	ft_strdel(&s_tmp);
	ft_strcat(*s, s_tmp = ft_ltoa(n));
	ft_strdel(&s_tmp);
	return (0);
}

static int		handle_precision(double n, int prec, char **s)
{
	char		*s_tmp;

	if ((n = n - (long long)n))
	{
		if (prec < 10)
			precision_smaller_than_10(n, prec, s);
		else
		{
			while (prec--)
			{
				n *= 10;
				if (!prec && (long long)((n - (long long)n) * 10) > 4
							&& (long long)((n - (long long)n) * 10) != 9)
					n += 1;
				ft_strcat(*s, s_tmp = ft_ltoa(n));
				ft_strdel(&s_tmp);
				n -= (long long)n;
			}
		}
	}
	else
		handle_no_number_after_decimal(prec, s);
	return (0);
}

static int		preci(double n, int t, char **s)
{
	double		d;
	long		nb;
	char		*s_tmp;

	nb = 0;
	d = n;
	d = n - (long)n;
	nb = d * ft_pow(10, 1);
	if (nb > 4)
		n += 1;
	ft_strcat(*s, s_tmp = ft_ltoa(n));
	ft_strdel(&s_tmp);
	if (t)
		ft_strcat(*s, ".");
	return (1);
}

char			*ft_dtoa_printf(double n, t_printf *p, int t)
{
	char		*s;
	char		*s_tmp;
	size_t		len;

	if (p->precision > 16 && (s = (long long)n == 0 ? ft_strdup("0.")
	: ft_strjoin(p->conv_ret, "\0")))
	{
		if (handle_precision(n, p->precision, &s))
			return (NULL);
		p->conv_ret = ft_strjoin(s, "");
		ft_strdel(&s);
		return (p->conv_ret);
	}
	len = ft_longlen(n) + p->precision + 1;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[0] = '\0';
	(n < 0 && (n = -n)) ? ft_strcpy(s, "-") : 0;
	if (p->precision == 0 && (preci(n, t, &s)))
		return (s);
	ft_strcat(s, s_tmp = ft_ltoa(n));
	ft_strdel(&s_tmp);
	return (p->precision > -1 && (ft_strcat(s, "."))
	&& (handle_precision(n, p->precision, &s)) ? NULL : s);
}
