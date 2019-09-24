/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:12 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/24 13:12:45 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	(*pc) += T_DIR;
	*arg_value = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
}

static void	exec_lfork(t_vm *vm, unsigned int arg_value)
{
	int		i;
	t_proc	*new;

	if (!(new = malloc(sizeof(t_proc))))
		ft_error(ERROR_MALLOC, -1, vm);
	new->alive = vm->proc->alive;
	new->carry = vm->proc->carry;
	new->head = vm->proc->head;
	new->n_champ = vm->proc->n_champ;
	new->pc = vm->proc->pc - T_DIR + arg_value;
	new->pc %= MEM_SIZE;
	i = -1;
	while (++i < 16)
		new->r[i] = vm->proc->r[i];
	new->wait = vm->proc->wait + 1;
	new->during_fork = 0;
	new->next = vm->beg;
	vm->beg = new;
}

void		op_lfork(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_lfork(vm, arg_value);
	ft_visu_d_message(vm, "lfork");
}
