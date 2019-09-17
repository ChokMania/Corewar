/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:25 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/17 13:41:34 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_DIR SIZE 2
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value)
{
	(*pc) += T_DIR;
	*arg_value = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
}

static void	exec_zjmp(t_vm *vm, unsigned int arg_value)
{
	if (vm->proc->carry == 1 && arg_value > IDX_MOD)
		vm->proc->pc -= 512 - (arg_value % IDX_MOD) + 3;
	else if (vm->proc->carry == 1)
		vm->proc->pc += (arg_value % IDX_MOD) - 3;
	else
		vm->proc->pc += T_DIR;
	if (vm->proc->pc < 0)
		vm->proc->pc = MEM_SIZE + vm->proc->pc;
	else if (vm->proc->pc > MEM_SIZE)
		vm->proc->pc %= MEM_SIZE;
}

void		op_zjmp(t_vm *vm, int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_zjmp(vm, arg_value);
}
