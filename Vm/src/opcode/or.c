/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:51 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/19 17:37:10 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
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

static void	op_or_suite(t_vm *vm, unsigned int *pc, unsigned int arg_size[3])
{
	if ((vm->arena[*pc][0] == 116) && (arg_size[0] = T_REG))
		arg_size[1] = T_IND;
	else if ((vm->arena[*pc][0] == 148) && (arg_size[0] = T_DIR))
		arg_size[1] = T_REG;
	else if ((vm->arena[*pc][0] == 164) && (arg_size[0] = T_DIR))
		arg_size[1] = T_DIR;
	else if ((vm->arena[*pc][0] == 180) && (arg_size[0] = T_DIR))
		arg_size[1] = T_IND;
	else if ((vm->arena[*pc][0] == 212) && (arg_size[0] = T_IND))
		arg_size[1] = T_REG;
	else if ((vm->arena[*pc][0] == 228) && (arg_size[0] = T_IND))
		arg_size[1] = T_DIR;
	else if ((vm->arena[*pc][0] == 244) && (arg_size[0] = T_IND))
		arg_size[1] = T_IND;
}

void		op_or(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				save;

	(*pc)++;
	save = (*pc);
	arg_size[2] = T_REG;
	if ((vm->arena[*pc][0] == 84) && (arg_size[0] = T_REG))
		arg_size[1] = T_REG;
	else if ((vm->arena[*pc][0] == 100) && (arg_size[0] = T_REG))
		arg_size[1] = T_DIR;
	else
		op_or_suite(vm, pc, arg_size);
	ft_arg(vm, pc, arg_value, arg_size);
	if (vm->arena[save][0] == 84 || vm->arena[save][0] == 100
		|| vm->arena[save][0] == 116 || vm->arena[save][0] == 148
		|| vm->arena[save][0] == 164 || vm->arena[save][0] == 180
		|| vm->arena[save][0] == 212 || vm->arena[save][0] == 228
		|| vm->arena[save][0] == 244)
	{
		exec_or(vm, arg_value, arg_size);
		ft_visu_d_message(vm, "or");
	}
}
