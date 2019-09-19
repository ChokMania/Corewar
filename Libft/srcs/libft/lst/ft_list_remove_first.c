/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_first.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:35:08 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/23 17:20:59 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_first_int(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (*begin_list && begin_list)
	{
		if ((*begin_list)->next)
		{
			*begin_list = tmp->next;
			free(tmp);
			tmp = NULL;
		}
	}
}

void	ft_list_remove_first_data(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (*begin_list && begin_list)
	{
		if ((*begin_list)->next)
		{
			*begin_list = tmp->next;
			ft_memdel(&tmp->data);
			free(tmp);
			tmp = NULL;
		}
	}
}
