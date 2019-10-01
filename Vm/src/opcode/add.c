/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:59 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/01 11:20:51 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	exec_add(t_vm *vm, unsigned int arg_value[3])
{
	vm->proc->r[arg_value[2]] = vm->proc->r[arg_value[0]]
		+ vm->proc->r[arg_value[1]];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_add(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;
	int				opcode[2];

	opcode[0] = 2;
	opcode[1] = 2;
	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, opcode, 3) % MEM_SIZE;
	if (ft_opcode(vm, pc, arg_value, arg_size, opcode)
	&& arg_size[0] == T_REG && arg_size[1] == T_REG && arg_size[2] == T_REG)
	{
		exec_add(vm, arg_value);
		ft_visu_d_message(vm, "add");
	}
	else
		*pc = jump;
}
