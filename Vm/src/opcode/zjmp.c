/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:25 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/30 12:15:35 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	*pc = (*pc + T_DIR) % MEM_SIZE;
	*arg_value = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8 | vm->arena[*pc][0];
}

static void	exec_zjmp(t_vm *vm, unsigned int arg_value)
{
	if (vm->proc->carry == 1)
		vm->proc->pc += (arg_value) - 3;
	vm->proc->pc %= MEM_SIZE;
}

void		op_zjmp(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_zjmp(vm, arg_value);
	ft_visu_d_message(vm, "zjmp");
}
