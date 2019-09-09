/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:12 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/25 11:39:18 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_fill_conv(t_ms *s)
{
	int		i;
	char	*(*function[13])(t_ms *s);

	function[0] = ft_char;
	function[1] = ft_string;
	function[2] = ft_int;
	function[3] = ft_int;
	function[4] = ft_mod;
	if (s->longlong == 1 && ft_fill_longlong(s))
		return (ft_longlong(s));
	i = 0;
	while (s->conv[i])
	{
		if (s->conv[i] == s->format[s->i])
			break ;
		i++;
	}
	return (ft_apply_width(s, ft_apply_accu(s, function[i](s))));
}

char	*ft_fill_text(t_ms *s)
{
	s->k = 0;
	if (!(s->tmp = (char *)malloc(sizeof(char) * (s->i - s->j + 1))))
		ft_error_miniprintf(s, -3);
	while (s->j < s->i)
	{
		s->tmp[s->k] = s->format[s->j];
		s->j++;
		s->k++;
	}
	s->tmp[s->k] = '\0';
	return (s->tmp);
}
