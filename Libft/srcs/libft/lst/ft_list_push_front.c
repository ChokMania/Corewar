/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:17:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/18 15:14:11 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	if (*begin_list && begin_list)
	{
		tmp = ft_create_elem(data);
		tmp->next = (*begin_list);
		if (!((*begin_list) = tmp))
			return (0);
	}
	else
	{
		if (!((*begin_list) = ft_create_elem(data)))
			return (0);
	}
	return (1);
}
