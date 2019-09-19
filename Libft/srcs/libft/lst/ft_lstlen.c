/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 00:52:33 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 00:52:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *beg)
{
	t_list		*tmp;
	int			i;

	i = 0;
	if (beg == NULL)
		return (0);
	tmp = beg;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
