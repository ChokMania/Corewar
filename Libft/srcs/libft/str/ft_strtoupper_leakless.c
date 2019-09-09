/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper_leakless.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:25:58 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 10:35:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtoupper_leakless(char *s)
{
	char	*dup;
	int		i;

	dup = ft_strdup(s);
	i = 0;
	while (dup && dup[i])
	{
		if (dup[i] >= 'a' && dup[i] <= 'z')
			dup[i] -= 32;
		++i;
	}
	ft_strdel(&s);
	return (dup);
}
