/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:35:03 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/19 14:42:01 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_list_lenght(t_proc *beg_real)
{
	int		i;
	t_proc	*beg;

	beg = beg_real;
	i = 0;
	while (beg && i++)
		beg = beg->next;
	return (i);
}

static void	ft_del_sta(t_vm *vm)
{
	t_proc	*del;

	del = vm->beg;
	vm->beg = vm->beg->next;
	free(del);
	del = NULL;
}

static void	ft_del_mid(t_vm *vm, int num)
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

static void	ft_del_end(t_vm *vm, int max)
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

void		ft_dead_proc(t_vm *vm, t_proc *current)
{
	int		num;
	int		max;
	t_proc	*tmp;

	tmp = vm->beg;
	num = 0;
	while (tmp && tmp != current && ++num)
		tmp = tmp->next;
	max = ft_list_count_vm(vm->beg);
	if (num < 1)
		max == 1 ? ft_victory(vm, current) : ft_del_sta(vm);
	else if (num == max)
		ft_del_end(vm, max);
	else
		ft_del_mid(vm, num);
}
