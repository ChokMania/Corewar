/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:16:40 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/29 15:18:44 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *last;
	t_list *sclast;
	t_list *lastsave;

	if (!(*begin_list) || !begin_list)
		return ;
	last = *begin_list;
	while (last->next)
		last = last->next;
	lastsave = last;
	while (1)
	{
		sclast = *begin_list;
		while (sclast->next && sclast->next != last)
			sclast = sclast->next;
		if (sclast == *begin_list)
		{
			last->next = sclast;
			sclast->next = 0;
			*begin_list = lastsave;
			break ;
		}
		last->next = sclast;
		last = last->next;
	}
}
