/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:21:47 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 12:08:37 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_last_int(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*beg;

	beg = *begin_list;
	tmp = beg;
	if (*begin_list && begin_list)
	{
		while (tmp->next)
		{
			beg = tmp;
			tmp = tmp->next;
		}
		free(beg->next);
		beg->next = NULL;
	}
}

void	ft_list_remove_last_data(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*beg;

	beg = *begin_list;
	tmp = beg;
	if (*begin_list && begin_list)
	{
		while (tmp->next)
		{
			beg = tmp;
			tmp = tmp->next;
		}
		ft_memdel(&beg->next->data);
		free(beg->next);
		beg->next = NULL;
	}
}
