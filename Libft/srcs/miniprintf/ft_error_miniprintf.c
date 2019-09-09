/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_miniprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:03 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/22 16:01:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_error_miniprintf(t_ms *s, int error)
{
	ft_putstr("An error occured in Miniprintf.\n");
	if (error == -1)
		free(s);
	if (error == -2)
	{
		ft_strdel(&(s->format));
		free(s);
	}
	if (error == -3)
	{
		ft_strdel(&(s->format));
		ft_strdel(&(s->output));
		free(s);
	}
	exit(0);
}
