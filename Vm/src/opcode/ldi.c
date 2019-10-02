/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:30 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 12:30:16 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	exec_ldi(t_vm *vm, unsigned int arg_value[3],
	unsigned arg_size[3])
{
	int i;

	if (arg_size[1] == T_REG)
		arg_value[1] = vm->proc->r[arg_value[1]];
	if (arg_size[0] == T_REG)
		arg_value[0] = vm->proc->r[arg_value[0]];
	i = (vm->proc->pc - (1 + arg_size[0] + arg_size[1] + arg_size[2])
		+ (arg_value[0] + arg_value[1])) % MEM_SIZE;
	vm->proc->r[arg_value[2]] = vm->arena[i % MEM_SIZE][0] << 24
		| vm->arena[(i + 1) % MEM_SIZE][0] << 16
		| vm->arena[(i + 2) % MEM_SIZE][0] << 8
		| vm->arena[(i + 3) % MEM_SIZE][0];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_ldi(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;

	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, 2, 3) % MEM_SIZE;
	if (ft_opcode(vm, pc, arg_value, arg_size, 2)
	&& (arg_size[0] == T_REG || arg_size[0] == T_DIR || arg_size[0] == T_IND)
	&& (arg_size[1] == T_REG || arg_size[1] == T_DIR)
	&& arg_size[2] == T_REG)
	{
		exec_ldi(vm, arg_value, arg_size);
		ft_visu_d_message(vm, "ldi");
	}
	else
		*pc = jump;
}
