/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_multi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:01:07 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/05 11:53:49 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_nbr_of_words(char const *s, char *c)
{
	long long	i;
	int			b;
	int			nbwords;

	i = 0;
	b = 0;
	nbwords = 0;
	while (s[i])
	{
		if (!ft_is_sep(s[i], c))
		{
			if (b == 0)
				nbwords++;
			b = 1;
		}
		else
			b = 0;
		i++;
	}
	return (nbwords);
}

static char		**ft_strsplit_two(char const *s, char *c)
{
	long long	i;
	long long	j;
	int			x;
	int			nbwords;
	char		**tab;

	nbwords = ft_nbr_of_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < nbwords && s[i])
	{
		x = 0;
		while (ft_is_sep(s[i], c) && s[i])
			i++;
		while (!ft_is_sep(s[i + x], c) && s[i + x])
			x++;
		tab[j] = ft_strsub(s, i, x);
		i = i + x;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit_multi(char const *s, char *c)
{
	if (s && c)
		return (ft_strsplit_two(s, c));
	return (NULL);
}
