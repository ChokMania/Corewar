/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:24:59 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/06 14:32:10 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_REG SIZE 1
** T_IND SIZE 2
** T_DIR SIZE 4
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;

	i = -1;
	while (++i < 2)
		if (arg_size[i] == T_REG)
		{
			(*pc) += T_REG;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) += T_IND;
			arg_size[i] = T_DIR + 1;
			arg_value[i] = vm->arena[*pc - 3][0] << 24
				| vm->arena[*pc - 2][0] << 16 | vm->arena[*pc - 1][0] << 8
				| vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) += T_DIR;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
		}
}

static void	exec_lld(t_vm *vm, unsigned int arg_value[3], unsigned int arg_size[3])
{
	if (arg_size[0] == T_DIR + 1 || arg_size[0] == T_IND)
		vm->proc->r[arg_value[1]] = arg_value[0] < IDX_MOD ? arg_value[0] : arg_value[0];
	vm->proc->carry = (vm->proc->carry + 1) % 2;
}

void		op_lld(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	(*pc)++;
	arg_size[2] = 0;
	arg_value[2] = 0;
	arg_size[1] = T_REG;
	if (vm->arena[*pc][0] == 144)
		arg_size[0] = T_DIR;
	else if (vm->arena[*pc][0] == 208)
		arg_size[0] = T_IND;
	else
		ft_error(ERROR_LDI, vm->proc->n_champ);
	ft_arg(vm, pc, arg_value, arg_size);
	exec_lld(vm, arg_value, arg_size);
}
