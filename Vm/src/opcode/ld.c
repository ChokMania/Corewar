/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:08 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/30 14:51:09 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;
	int		ret;

	i = -1;
	ret = 1;
	while (++i < 2)
		if (arg_size[i] == T_REG)
		{
			(*pc) = (*pc + T_REG) % MEM_SIZE;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
			if (arg_value[i] > 15)
				ret = 0;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) = (*pc + T_IND) % MEM_SIZE;
			arg_size[i] = T_DIR + 1;
			arg_value[i] = vm->arena[(*pc - 3) % MEM_SIZE][0] << 24
				| vm->arena[(*pc - 2) % MEM_SIZE][0] << 16
				| vm->arena[(*pc - 1) % MEM_SIZE][0] << 8 | vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) = (*pc + T_DIR) % MEM_SIZE;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8
				| vm->arena[*pc][0];
		}
	return (ret);
}

static void	exec_ld(t_vm *vm, unsigned int arg_value[2],
	unsigned int arg_size[2])
{
	int i;

	//IDX MOD
	i = -arg_value[0] + (arg_size[0] + arg_size[1]) - 1;
	if (arg_size[0] == T_DIR + 1)
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
	unsigned int	arg_value[2];
	unsigned int	arg_size[2];

	(*pc) = (*pc + 1) % MEM_SIZE;
	recup_opc(vm->arena[*pc][0], arg_size);
	if (ft_arg(vm, pc, arg_value, arg_size))
	{
		exec_ld(vm, arg_value, arg_size);
		ft_visu_d_message(vm, "ld");
	}
}
