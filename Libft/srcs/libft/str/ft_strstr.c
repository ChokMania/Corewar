/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:17:48 by judumay           #+#    #+#             */
/*   Updated: 2018/11/19 18:48:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	char	*str;

	if (*needle == '\0')
		return ((char*)haystack);
	i = ft_strlen(needle);
	str = (char*)haystack;
	while (*str)
	{
		if (ft_memcmp(str, needle, i) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
