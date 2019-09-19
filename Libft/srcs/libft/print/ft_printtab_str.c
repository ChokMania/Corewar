/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:20:12 by judumay           #+#    #+#             */
/*   Updated: 2019/06/05 17:03:30 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printtab_str(char **str, int lenght)
{
	int i;

	i = -1;
	if (!str)
		return ;
	while (++i < lenght)
		ft_putendl(str[i]);
}
