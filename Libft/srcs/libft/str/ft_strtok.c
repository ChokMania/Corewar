/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:24:34 by judumay           #+#    #+#             */
/*   Updated: 2018/11/19 18:48:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	ft_search(char tmp, const char *sep)
{
	int		index;

	index = 0;
	while (sep[index])
	{
		if (sep[index] != tmp)
			index++;
		else
			break ;
	}
	return (sep[index]);
}

char		*ft_strtok(char *str, const char *sep)
{
	static char	*stock = NULL;
	char		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = str;
	while (*stock != '\0')
	{
		if (i == 0 && *stock != ft_search(*stock, sep))
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == ft_search(*stock, sep))
		{
			*stock = '\0';
			stock++;
			break ;
		}
		stock++;
	}
	return (ptr);
}
