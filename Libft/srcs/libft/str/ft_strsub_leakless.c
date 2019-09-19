/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_leakless.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:25:38 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 10:35:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub_leakless(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (NULL);
	cpy = ft_strnew(len);
	if (!cpy)
		return (NULL);
	while (i < len)
		cpy[i++] = s[start++];
	ft_strdel(&s);
	return (cpy);
}
