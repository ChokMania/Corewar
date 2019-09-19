/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:15:31 by judumay           #+#    #+#             */
/*   Updated: 2018/11/19 18:48:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		ft_words(char *str, char c)
{
	int word;
	int space;
	int nb_words;
	int i;

	i = 0;
	nb_words = 0;
	word = 0;
	space = 1;
	while (str[i] != '\0')
	{
		if (str[i] != c && !word)
		{
			word = 1;
			space = 0;
			nb_words++;
		}
		if (str[i] == c && !space)
		{
			word = 0;
			space = 1;
		}
		i++;
	}
	return (nb_words);
}

static	int		ft_beginning(int i, char *str, int tab[], char c)
{
	int beg;

	beg = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			beg = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			tab[0] = i - beg;
			break ;
		}
		i++;
	}
	return (beg);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		tab[1];
	char	**string;

	if (!s || !c)
		return (NULL);
	i = 0;
	k = 0;
	if (!(string = (char**)malloc(sizeof(char*) * (ft_words((char*)s, c) + 1))))
		return (NULL);
	while (i < ft_words((char*)s, c))
	{
		j = -1;
		k = ft_beginning(k, (char*)s, tab, c);
		if (!(string[i] = (char*)malloc(sizeof(char) * (tab[0] + 1))))
			return (NULL);
		while (++j < tab[0])
			string[i][j] = s[k++];
		string[i][j] = '\0';
		i++;
	}
	string[i] = 0;
	return (string);
}
