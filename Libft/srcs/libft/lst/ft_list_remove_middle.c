/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_middle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:40:03 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 11:41:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_middle_int(t_list **begin_list, t_list *elem)
{
	t_list	*tmp;
	t_list	*tmpnext;

	tmp = *begin_list;
	if (*begin_list && begin_list)
	{
		while (tmp->next->next && tmp->next != elem)
			tmp = tmp->next;
		tmpnext = tmp->next;
		tmp->next = tmp->next->next;
		free(tmpnext);
		tmpnext = NULL;
	}
}

void	ft_list_remove_middle_data(t_list **begin_list, t_list *elem)
{
	t_list	*tmp;
	t_list	*tmpnext;

	tmp = *begin_list;
	if (*begin_list && begin_list)
	{
		while (tmp && tmp->next && tmp->next != elem)
			tmp = tmp->next;
		tmpnext = tmp->next;
		tmp->next = tmp->next->next;
		ft_memdel(&tmpnext->data);
		free(tmpnext);
		tmpnext = NULL;
	}
}
