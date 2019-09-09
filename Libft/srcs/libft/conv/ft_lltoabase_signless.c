/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoabase_signless.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:25:13 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 10:35:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_lltoabase_signless(long long nbr, int base)
{
	unsigned long long		nb;
	char					*s;
	char					tmp;

	if (!(s = ft_strnew(0)))
		return (NULL);
	nb = (unsigned long long)nbr;
	if (nbr < 0)
		nb = (unsigned long long)-nbr;
	if (!nb)
		return ((s = ft_stradd_leakless(s, '0')));
	while (nb && base > 1 && base < 37)
	{
		tmp = (char)(nb % (unsigned long long)base);
		if (tmp > 9)
			tmp += 'a' - 10;
		else
			tmp += '0';
		s = ft_stradd_leakless(s, tmp);
		nb /= (unsigned long long)base;
	}
	return ((s = ft_strrev_leakless(s)));
}
