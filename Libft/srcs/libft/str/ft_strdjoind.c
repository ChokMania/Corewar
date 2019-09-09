/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:56:10 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 16:20:16 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoind(char *s1, char *s2)
{
	char	*str;

	if (s2)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
		ft_strdel(&s2);
		ft_strdel(&s1);
		return (str);
	}
	return (s1);
}
