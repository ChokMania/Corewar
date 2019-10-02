/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:25 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 13:41:56 by anmauffr         ###   ########.fr       */
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

// void		op_zjmp(t_vm *vm, unsigned int *pc)
// {
// 	unsigned int	arg_value[3];
// 	unsigned int	arg_size[3];
// 	int				jump;

// 	// (*pc) = (*pc + 1) % MEM_SIZE;
// 	jump = *pc;
// 	// jump += recup_opc(vm->arena[*pc][0], arg_size, 2, 3) % MEM_SIZE;
// 	if (ft_opcode(vm, arg_value, arg_size, 2)
// 	&& arg_size[0] == T_REG && arg_size[1] == T_REG && arg_size[2] == T_REG)
// 	{
// 		exec_add(vm, arg_value);
// 		ft_visu_d_message(vm, "add");
// 	}
// 	else
// 		*pc = jump;
// }