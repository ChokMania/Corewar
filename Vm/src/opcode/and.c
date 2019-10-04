/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:34 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/04 12:32:10 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static void	exec_and(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	if (arg_size[0] == T_REG)
		vm->proc->r[arg_value[2]] = arg_size[1] == T_REG
			? vm->proc->r[arg_value[0]] & vm->proc->r[arg_value[1]]
			: vm->proc->r[arg_value[0]] & arg_value[1];
	else
		vm->proc->r[arg_value[2]] = arg_size[1] == T_REG
			? arg_value[0] & vm->proc->r[arg_value[1]]
			: arg_value[0] & arg_value[1];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
	ft_visu_d_message(vm, "and");
}*/

static void	exec_and(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	int		realpc;
	int		i;

	i = -1;
	realpc = vm->proc->pc - arg_size[0] - arg_size[1] - arg_size[2] - 1;
	if (arg_size[0] == T_IND && (realpc -= 2) > -1 && arg_size[1] == T_IND)
		realpc -= 2;
	while (++i < 2)
		if (arg_size[i] == T_REG)
			arg_value[i] = vm->proc->r[arg_value[i]];
		else if (arg_size[i] == T_IND)
		{
			arg_value[i] =
			vm->arena[idx_mod(realpc, arg_value[i])][0] << 24
			| vm->arena[idx_mod(realpc, arg_value[i] + 1)][0] << 16
			| vm->arena[idx_mod(realpc, arg_value[i] + 2)][0] << 8
			| vm->arena[idx_mod(realpc, arg_value[i] + 3)][0];
		}
	vm->proc->r[arg_value[2]] = arg_value[0] & arg_value[1];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}


void		op_and(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;

	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, 4, 3) % MEM_SIZE;
	if (ft_opcode(vm, arg_value, arg_size, 4)
	&& (arg_size[0] == T_REG || arg_size[0] == T_DIR || arg_size[0] == T_IND)
	&& (arg_size[1] == T_REG || arg_size[1] == T_DIR || arg_size[0] == T_IND)
	&& arg_size[2] == T_REG)
		exec_and(vm, arg_value, arg_size);
	else
		*pc = jump;
}
