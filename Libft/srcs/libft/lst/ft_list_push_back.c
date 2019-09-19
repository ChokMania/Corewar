/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:56:35 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/18 15:14:28 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *tmp;

	if (*begin_list && begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_create_elem(data)))
			return (0);
	}
	else
	{
		if (!((*begin_list) = ft_create_elem(data)))
			return (0);
	}
	return (1);
}
