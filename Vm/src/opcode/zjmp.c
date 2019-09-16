/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:25 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/16 10:17:12 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_DIR SIZE 2
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	if (arg_size[0] == T_REG)
	{
		(*pc) += T_REG;
		arg_size[0] = T_REG;
		arg_value[0] = vm->arena[*pc][0] - 0x01;
	}
	else if (arg_size[0] == T_DIR)
	{
		(*pc) += T_DIR;
		arg_size[0] = T_DIR;
		arg_value[0] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
	}
	else if (arg_size[0] == T_IND)
	{
		(*pc) += T_DIR;
		arg_size[0] = T_IND;
		arg_value[0] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
	}
}

static void	exec_zjmp(t_vm *vm, unsigned int arg_value[3]
	, unsigned int arg_size[3])
{
	(void)arg_size;
	if (vm->proc->carry == 1 && arg_value[0] > IDX_MOD)
		vm->proc->pc -= 512 - (arg_value[0] % IDX_MOD) + 3;
	else if (vm->proc->carry == 1)
		vm->proc->pc += (arg_value[0] % IDX_MOD) - 3;
	else
		vm->proc->pc += arg_size[1];
	if (vm->proc->pc < 0)
		vm->proc->pc = MEM_SIZE + vm->proc->pc;
	else if (vm->proc->pc > MEM_SIZE)
		vm->proc->pc %= MEM_SIZE;
}

void		op_zjmp(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	arg_size[0] = T_DIR;
	arg_size[1] = 0;
	arg_value[1] = 0;
	arg_size[2] = 0;
	arg_value[2] = 0;
	ft_arg(vm, pc, arg_value, arg_size);
	exec_zjmp(vm, arg_value, arg_size);
}
