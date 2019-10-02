/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:08 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 14:57:56 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	exec_ld(t_vm *vm, unsigned int arg_value[2],
	unsigned int arg_size[2])
{
	int i;

	i = -arg_value[0] + (arg_size[0] + arg_size[1]) - 1;
	if (arg_size[0] == T_DIR)
		vm->proc->r[arg_value[1]] = arg_value[0];
	else if (arg_size[0] == T_IND)
	{
		i = vm->proc->pc - i;
		vm->proc->r[arg_value[1]] = vm->arena[i % MEM_SIZE][0] << 24
			| vm->arena[(i + 1) % MEM_SIZE][0] << 16
			| vm->arena[(i + 2) % MEM_SIZE][0] << 8
			| vm->arena[(i + 3) % MEM_SIZE][0];
	}
	vm->proc->carry = !vm->proc->r[arg_value[1]] ? 1 : 0;
}

void		op_ld(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;

	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, 4, 2) % MEM_SIZE;
	if (ft_opcode(vm, arg_value, arg_size, 4)
	&& (arg_size[0] == T_DIR || arg_size[0] == T_IND)
	&& arg_size[1] == T_REG)
	{
		exec_ld(vm, arg_value, arg_size);
		ft_visu_d_message(vm, "ld");
	}
	else
		*pc = jump;
}
