/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:16 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/16 10:31:26 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_REG SIZE 1
** T_IND SIZE 2
** T_DIR SIZE 2
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;

	i = -1;
	while (++i < 3)
		if (arg_size[i] == T_REG)
		{
			(*pc) += T_REG;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) += T_DIR;
			arg_size[i] = T_DIR;
			arg_value[i] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) += T_DIR;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
		}
}

static void	exec_sti(t_vm *vm, unsigned int arg_value[3]
	, unsigned int arg_size[3])
{
	int		i;
	int		index;
	int		tmp;

	index = 0;
	if (arg_size[1] == T_REG)
		index += vm->proc->r[arg_value[1]] - T_REG;
	else if (arg_size[1] == T_DIR || arg_size[1] == T_IND)
		index += arg_value[1] - T_DIR;
	if (arg_size[2] == T_REG)
		index += vm->proc->r[arg_value[2]] - T_REG;
	else if (arg_size[2] == T_DIR)
		index += arg_value[2] - T_DIR;
	if (vm->proc->pc + index >= MEM_SIZE)
		index -= (IDX_MOD - index % IDX_MOD + vm->proc->pc - 2) % MEM_SIZE;
	else
		index %= IDX_MOD;
	i = 4;
	tmp = vm->proc->r[arg_value[0]];
	while (--i >= 0)
	{
		vm->arena[index + i][0] = tmp % 256;
		vm->arena[index + i][1] = vm->proc->n_champ;
		tmp >>= 8;
	}
}

void		op_sti(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	(*pc)++;
	arg_size[0] = T_REG;
	if ((vm->arena[*pc][0] == 84 || vm->arena[*pc][0] == 88)
		&& (arg_size[1] = T_REG))
		arg_size[2] = vm->arena[*pc][0] == 84 ? T_REG : T_DIR;
	else if ((vm->arena[*pc][0] == 100 || vm->arena[*pc][0] == 104)
		&& (arg_size[1] = T_DIR))
		arg_size[2] = vm->arena[*pc][0] == 100 ? T_REG : T_DIR;
	else if ((vm->arena[*pc][0] == 116 || vm->arena[*pc][0] == 120)
		&& (arg_size[1] = T_IND))
		arg_size[2] = vm->arena[*pc][0] == 116 ? T_REG : T_DIR;
	else
		ft_error(ERROR_STI, vm->proc->n_champ, vm);
	ft_arg(vm, pc, arg_value, arg_size);
	exec_sti(vm, arg_value, arg_size);
	vm->option_visu == 1 ? visual_sti(vm, arg_value, arg_size) : 0;
}
