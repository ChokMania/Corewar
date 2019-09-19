/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:00:32 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/22 16:00:33 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_check_accu(t_ms *s)
{
	if (s->format[s->i] && s->format[s->i] == '.')
		s->i++;
	else
		return ;
	if (s->format[s->i] && ft_isdigit(s->format[s->i]))
	{
		s->accu = ft_atoi(s->format + s->i);
		while (s->format[s->i] && ft_isdigit(s->format[s->i]))
			s->i++;
	}
}

char	*ft_apply_accu(t_ms *s, char *str)
{
	int		i;
	char	*result;

	if (s->accu)
	{
		if (!(result = (char *)malloc(sizeof(char) * (s->accu + 1))))
		{
			ft_strdel(&str);
			ft_error_miniprintf(s, -3);
		}
		i = 0;
		while (s->accu-- > 0)
		{
			result[i] = str[i];
			i++;
		}
		result[i] = '\0';
		ft_strdel(&str);
		return (result);
	}
	else
		return (str);
}
