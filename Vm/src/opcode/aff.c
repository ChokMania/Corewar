/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:24:51 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 10:57:46 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	exec_aff(t_vm *vm, unsigned int arg_value[3])
{
	vm->option_visu == 0 && vm->option_visu_d == 0 && vm->option_dump <= 0
		? ft_printf("%c", vm->proc->r[arg_value[0]] % 256) : 0;
}

void		op_aff(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				size[2];
	int				jump;

	size[0] = 4;
	size[1] = 2;
	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, size, 1) % MEM_SIZE;
	if (ft_opcode(vm, pc, arg_value, arg_size, size)
	&& arg_size[0] == T_REG)
	{
		exec_aff(vm, arg_value);
		ft_visu_d_message(vm, "aff");
	}
	else
		*pc = jump;
}
