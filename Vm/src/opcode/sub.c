/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:04 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/01 15:22:53 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	exec_sub(t_vm *vm, unsigned int arg_value[3])
{
	vm->proc->r[arg_value[2]] = vm->proc->r[arg_value[0]]
		- vm->proc->r[arg_value[1]];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_sub(t_vm *vm, unsigned int *pc)
{
		unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;
	int				size[2];

	size[0] = 2;
	size[1] = 2;
	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, size, 3) % MEM_SIZE;
	if (ft_opcode(vm, pc, arg_value, arg_size, size)
	&& arg_size[0] == T_REG && arg_size[1] == T_REG && arg_size[2] == T_REG)
	{
		exec_sub(vm, arg_value);
		ft_visu_d_message(vm, "add");
	}
	else
		*pc = jump;
}
