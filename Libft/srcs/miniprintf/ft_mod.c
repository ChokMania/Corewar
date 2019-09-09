/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:21 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/25 11:35:19 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_mod(t_ms *s)
{
	char *tmp;

	tmp = va_arg(s->va, char *);
	if (ft_strcmp(tmp, "NOEND") == 0)
	{
		s->noend = 1;
		return (ft_strdup(""));
	}
	if (ft_strcmp(tmp, "UNDER") == 0)
		return (ft_strdup("\x1b[4m"));
	if (ft_strcmp(tmp, "END") == 0)
		return (ft_strdup("\x1b[0m"));
	if (ft_strcmp(tmp, "BOLD") == 0)
		return (ft_strdup("\x1b[1m"));
	if (ft_strcmp(tmp, "WHITE") == 0)
		return (ft_strdup("\x1b[37m"));
	if (ft_strcmp(tmp, "GREEN") == 0)
		return (ft_strdup("\x1b[32m"));
	if (ft_strcmp(tmp, "YELLOW") == 0)
		return (ft_strdup("\x1b[33m"));
	if (ft_strcmp(tmp, "RED") == 0)
		return (ft_strdup("\x1b[31m"));
	if (ft_strcmp(tmp, "BLUE") == 0)
		return (ft_strdup("\x1b[34m"));
	return (ft_strdup("%"));
}
