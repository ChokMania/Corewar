/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:34 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/25 10:37:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_set_struct_mini(t_ms *s)
{
	if (!(s->output = ft_strnew(0)))
		ft_error_miniprintf(s, -2);
	s->conv = "csdi%";
}
