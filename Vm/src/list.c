/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:35:03 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/25 10:15:33 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				ft_list_lenght(t_proc *beg_real)
{
	int		i;
	t_proc	*beg;

	beg = beg_real;
	i = 0;
	while (beg && i++)
		beg = beg->next;
	return (i);
}

void	ft_dead_proc(t_vm *vm, t_proc *current)
{
	t_proc	*del;
	int		is_first;

	is_first = 1;
	del = vm->beg;
	while (del != current && !(is_first = 0))
		del = del->next;
	if (is_first)
	{
		current = current->next;
		vm->beg = current;
		free(del);
	}
	else if (del->next)
	{
		current = vm->beg;
		while (current->next != del)
			current = current->next;
		current->next = del->next;
		free(del);
	}
	else
	{
		current = NULL;
		free(del);
	}
}
