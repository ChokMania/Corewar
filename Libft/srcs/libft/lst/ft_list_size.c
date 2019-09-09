/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:32:07 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/29 15:17:47 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int count;

	if (!begin_list)
		return (0);
	count = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
