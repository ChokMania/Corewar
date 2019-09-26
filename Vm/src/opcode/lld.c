/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:24:59 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/26 12:21:11 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;

	i = -1;
	while (++i < 2)
		if (arg_size[i] == T_REG)
		{
			(*pc) = ((*pc) + T_REG) % MEM_SIZE;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) = ((*pc) + T_IND) % MEM_SIZE;
			arg_size[i] = T_DIR + 1;
			arg_value[i] = vm->arena[(*pc - 3) % MEM_SIZE][0] << 24
				| vm->arena[(*pc - 2) % MEM_SIZE][0] << 16 | vm->arena[(*pc - 1) % MEM_SIZE][0] << 8
				| vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) += T_DIR;
			(*pc) %= MEM_SIZE;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8 | vm->arena[*pc][0];
		}
}

static void	exec_lld(t_vm *vm, unsigned int arg_value[3]
	, unsigned int arg_size[3])
{
	if (arg_value[1] <= 15)
	{
		if (arg_size[0] == T_DIR + 1 || arg_size[0] == T_IND)
			vm->proc->r[arg_value[1]] = arg_value[0] < IDX_MOD
				? arg_value[0] : arg_value[0];
		vm->proc->carry = arg_value[0] == 0 ? 1 : 0;
	}
}

void		op_lld(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				save;

	(*pc)++;
	(*pc) %= MEM_SIZE;
	save = (*pc);
	arg_size[2] = 0;
	arg_value[2] = 0;
	arg_size[1] = T_REG;
	if (vm->arena[*pc][0] == 144)
		arg_size[0] = T_DIR;
	else if (vm->arena[*pc][0] == 208)
		arg_size[0] = T_IND;
	ft_arg(vm, pc, arg_value, arg_size);
	if (vm->arena[save][0] == 144 || vm->arena[save][0] == 208)
	{
		exec_lld(vm, arg_value, arg_size);
		ft_visu_d_message(vm, "lld");
	}
}
