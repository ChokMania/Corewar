/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:35:03 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/24 18:44:48 by judumay          ###   ########.fr       */
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

static t_proc	*ft_del_sta(t_vm *vm)
{
	t_proc	*del;

	del = NULL;
	if (vm->beg)
	{
		del = vm->beg;
		vm->beg = vm->beg->next;
		free(del);
		return (vm->beg);
	}
	return (NULL);
}

static t_proc	*ft_del_mid(t_vm *vm, int num)
{
	int		i;
	t_proc	*del;
	t_proc	*prev;

	prev = vm->beg;
	del = vm->beg;
	i = 0;
	while (del && del->next && i++ < num)
		del = del->next;
	while (prev->next != del)
		prev = prev->next;
	prev->next = del->next ? del->next : NULL;
	free(del);
	return(prev->next);
}

static t_proc	*ft_del_end(t_vm *vm, int max)
{
	int		i;
	t_proc	*elem;

	elem = vm->beg;
	i = 0;
	while (i++ < max - 1)
		elem = elem->next;
	free(elem->next);
	elem->next = NULL;
	return (NULL);
}

t_proc		*ft_dead_proc(t_vm *vm, t_proc *current)
{
	int		num;
	int		max;
	t_proc	*tmp;
	t_proc	*prev;

	tmp = vm->beg;
	prev = NULL;
	num = 0;
	while (tmp && tmp != current && ++num)
		tmp = tmp->next;
	max = ft_list_count_vm(vm->beg);
	if (num < 1)
		max == 1 ? ft_victory(vm, current) : (prev = ft_del_sta(vm));
	else if (num == max)
		prev = ft_del_end(vm, max);
	else
		prev = ft_del_mid(vm, num);
	return (prev);
}
