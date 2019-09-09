/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:52:48 by judumay           #+#    #+#             */
/*   Updated: 2019/06/24 16:17:09 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

int		ft_longlen(long n)
{
	int				len;
	unsigned long	nb;

	len = 1;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
