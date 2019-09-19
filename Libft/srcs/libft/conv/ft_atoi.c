/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:05:23 by judumay           #+#    #+#             */
/*   Updated: 2019/02/19 20:03:08 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int nb;
	int i;
	int neg;

	neg = 0;
	i = 0;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = (nb * 10) + (str[i] - '0');
			i++;
		}
	if (neg == 1)
		nb *= -1;
	return (nb);
}
