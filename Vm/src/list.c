/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:35:03 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 11:14:22 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_list_len(t_proc *beg_real)
{
	int		i;
	t_proc	*beg;

	beg = beg_real;
	i = 0;
	while (beg && i++)
		beg = beg->next;
	return (i);
}

static void ft_del_sta(t_vm *vm)
{
	t_proc	*del;

	del = vm->beg;
	vm->beg = vm->beg->next;
	free(del);
	del = NULL;
}

static void ft_del_mid(t_vm *vm, int num)
{
	int		i;
	t_proc	*elem;
	t_proc	*del;
	
	elem = vm->beg;
	i = 0;
	while (i++ < num - 1)
		elem = elem->next;
	del = elem->next;
	elem->next = elem->next->next;
	free(del);
	del = NULL;
}

static void ft_del_end(t_vm *vm, int max)
{
	int		i;
	t_proc	*elem;

	elem = vm->beg;
	i = 0;
	while (i++ < max - 1)
		elem = elem->next;
	free(elem->next);
	elem->next = NULL;
}

/*
** SI UN PROC N'A PAS DIT QU'IL ETAIT EN VIE UNE SEULE FOIS ALORS
** C'EST LA MORT
*/

void		ft_dead_proc(t_vm *vm)
{
	int		num;
	int		max;
	t_proc	*tmp;

	tmp = vm->beg;
	num = 0;
	while (tmp && ++num)
		tmp = tmp->next;
	max = ft_list_len(vm->beg);
	if (num == 1)
		ft_del_sta(vm);
	else if (num == max)
		ft_del_end(vm, max);
	else
		ft_del_mid(vm, num);
}
