/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:51 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/28 18:34:08 by judumay          ###   ########.fr       */
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
	while (++i < 3)
		if (arg_size[i] == T_REG)
		{
			(*pc) = ((*pc) + T_REG) % MEM_SIZE;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
			if (arg_value[i] > 15)
				ret = 0;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) = ((*pc) + T_IND) % MEM_SIZE;
			arg_size[i] = T_DIR + 1;
			arg_value[i] = vm->arena[((*pc) - 3) % MEM_SIZE][0] << 24
				| vm->arena[((*pc) - 2) % MEM_SIZE][0] << 16
				| vm->arena[((*pc) - 1) % MEM_SIZE][0] << 8
				| vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) = ((*pc) + T_DIR) % MEM_SIZE;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[((*pc) - 1) % MEM_SIZE][0] << 8
			| vm->arena[*pc][0];
		}
	return (ret);
}

static void	exec_or(t_vm *vm, unsigned int arg_value[3]
	, unsigned int arg_size[3])
{
	if (arg_size[0] == T_REG)
		vm->proc->r[arg_value[2]] = arg_size[1] == T_REG
			? vm->proc->r[arg_value[0]] | vm->proc->r[arg_value[1]]
			: vm->proc->r[arg_value[0]] | arg_value[1];
	else
		vm->proc->r[arg_value[2]] = arg_size[1] == T_REG
			? arg_value[0] | vm->proc->r[arg_value[1]]
			: arg_value[0] | arg_value[1];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_or(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	(*pc) = ((*pc) + 1) % MEM_SIZE;
	recup_opc(vm->arena[*pc][0], arg_size);
	if (ft_arg(vm, pc, arg_value, arg_size))
	{
		exec_or(vm, arg_value, arg_size);
		ft_visu_d_message(vm, "or");
	}
}
