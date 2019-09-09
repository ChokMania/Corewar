/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:09:42 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/05 11:53:56 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_nb_to_remove(const char *s, char *sep)
{
	int		nb_to_remove;
	int		i;

	i = 0;
	nb_to_remove = 0;
	while (s[i])
	{
		if (ft_is_sep(s[i], sep))
			nb_to_remove++;
		i++;
	}
	return (nb_to_remove);
}

char			*ft_strremove_char(char const *s, char *sep)
{
	int		i;
	int		j;
	int		len;
	int		nb_to_remove;
	char	*str;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	if (!sep)
		return ((char *)s);
	len = ft_strlen(s);
	nb_to_remove = ft_nb_to_remove(s, sep);
	if (!(str = (char *)malloc(sizeof(char) * (len - nb_to_remove + 1))))
		return (NULL);
	while (s[++i])
		if (!ft_is_sep(s[i], sep))
		{
			str[j] = s[i];
			j++;
		}
	str[j] = '\0';
	return (str);
}
