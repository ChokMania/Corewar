/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:20 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/26 14:33:11 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	(*pc) = (*pc + T_DIR) % MEM_SIZE;
	*arg_value = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8 | vm->arena[*pc][0];
}

static void	exec_fork(t_vm *vm, unsigned int arg_value)
{
	int		i;
	t_proc	*new;

	if (!(new = malloc(sizeof(t_proc))))
		ft_error(ERROR_MALLOC, -1, vm);
	new->creation = vm->cycle;
	new->last_live = vm->proc->last_live;
	new->alive = vm->proc->alive;
	new->carry = vm->proc->carry;
	new->head = vm->proc->head;
	new->n_champ = vm->proc->n_champ;
	new->number = ++vm->nb_proc;
	new->pc = arg_value % MEM_SIZE < IDX_MOD
		|| MEM_SIZE - arg_value % MEM_SIZE < IDX_MOD
		? vm->proc->pc - T_DIR + arg_value
		: vm->proc->pc - T_DIR - (arg_value % IDX_MOD);
	new->pc %= MEM_SIZE;
	i = -1;
	while (++i < 16)
		new->r[i] = vm->proc->r[i];
	new->wait = vm->proc->wait;
	new->next = vm->beg;
	vm->beg = new;
}

void		op_fork(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_fork(vm, arg_value);
	ft_visu_d_message(vm, "fork");
}
