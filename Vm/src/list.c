/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:35:03 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/25 13:47:55 by mabouce          ###   ########.fr       */
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

void	ft_dead_proc(t_vm *vm, t_proc **current)
{
	t_proc	*del;
	int		is_first;

	is_first = 1;
	del = vm->beg;
	while (del && del != *current && !(is_first = 0))
		del = del->next;
	if (is_first)
	{
		ft_list_count_vm(vm->beg) == 1 ? ft_victory(vm, *current) : 0;

		*current = (*current)->next;
		vm->beg = *current;
		free(del);
	}
	else if (del && del->next)
	{
		*current = vm->beg;
		while ((*current)->next != del)
			*current = (*current)->next;
		(*current)->next = del->next;
		*current = (*current)->next;
		free(del);
	}
	else
	{
		free(del);
		*current = NULL;
	}
}

void		ft_print_proc(t_proc *beg)
{
	while (beg)
	{
		miniprintf("name : %s\t numero : %d\n", beg->head.prog_name, beg->number);
		beg = beg->next;
	}
}

void	ft_reverse_list(t_proc **beg)
{
	t_proc	*last;
	t_proc	*last_save;
	t_proc	*prev;

	last = *beg;
	if (*beg && (*beg)->next)
	{
		while (last->next)
			last = last->next;
		last_save = last;
		while (last != *beg)
		{
			prev = *beg;
			while (prev && prev->next && prev->next != last)
				prev = prev->next;
			last->next = prev;
			last = last->next;
		}
		last->next = NULL;
		*beg = last_save;
	}
}