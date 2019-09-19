/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:54 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/25 11:39:28 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

int		ft_is_conv(char c, t_ms *s)
{
	int	i;

	i = 0;
	while (s->conv[i])
	{
		if (c == s->conv[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_read_format(t_ms *s)
{
	s->i = -1;
	s->j = 0;
	while (s->format[++s->i])
	{
		if (s->format[s->i] == '%')
		{
			if (!(s->output = ft_strdjoind(s->output
							, ft_fill_text(s))))
				ft_error_miniprintf(s, -3);
			s->i++;
			if (s->format[s->i] == '0')
				s->zero_fill = 1;
			ft_check_width(s);
			ft_check_accu(s);
			ft_check_longlong(s);
			if (!ft_is_conv(s->format[s->i], s))
				ft_error_miniprintf(s, -3);
			if (!(s->output = ft_strdjoind(s->output
							, ft_fill_conv(s))))
				ft_error_miniprintf(s, -3);
			s->j = s->i + 1;
		}
	}
	if (!(s->output = ft_strdjoind(s->output, ft_fill_text(s))))
		ft_error_miniprintf(s, -3);
}

int		miniprintf(const char *format, ...)
{
	t_ms		*s;

	if (!(s = (t_ms *)malloc(sizeof(t_ms))))
		ft_error_miniprintf(s, 0);
	ft_bzero(s, sizeof(t_ms));
	va_start(s->va, format);
	if (!(s->format = ft_strdup((char *)format)))
		ft_error_miniprintf(s, -1);
	ft_set_struct_mini(s);
	ft_read_format(s);
	if (s->noend == 0)
		s->output = ft_strdjoin(s->output, "\x1b[0m");
	ft_putstr(s->output);
	ft_strdel(&(s->format));
	ft_strdel(&(s->output));
	free(s);
	va_end(s->va);
	return (0);
}
