/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoabase_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:25:21 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 10:35:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_lltoabase_unsigned(unsigned long long nbr, int base)
{
	char			*s;
	char			tmp;

	s = ft_strnew(0);
	if (!nbr)
		s = ft_stradd_leakless(s, '0');
	while (nbr && base > 1 && base < 37)
	{
		tmp = (char)(nbr % (unsigned)base);
		if (tmp > 9)
			tmp += 'a' - 10;
		else
			tmp += '0';
		s = ft_stradd_leakless(s, (char)tmp);
		nbr /= (unsigned)base;
	}
	return ((s = ft_strrev_leakless(s)));
}
