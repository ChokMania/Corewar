/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:30 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/26 12:30:04 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;
	int		err;

	i = -1;
	err = 1;
	while (++i < 3)
		if (arg_size[i] == T_REG)
		{
			(*pc) += T_REG;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
			if (arg_value[i] > 15)
				err = 0;
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
	return (err);
}

static void	exec_ldi(t_vm *vm, unsigned int arg_value[3])
{
	vm->proc->r[arg_value[2]] = (arg_value[0] + arg_value[1]) % IDX_MOD;
}

void		op_ldi(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				save;

	(*pc)++;
	save = (*pc);
	arg_size[2] = T_REG;
	if ((vm->arena[*pc][0] == 54 || vm->arena[*pc][0] == 100)
		&& (arg_size[0] = T_REG))
		arg_size[1] = vm->arena[*pc][0] == 54 ? T_REG : T_DIR;
	else if ((vm->arena[*pc][0] == 148 || vm->arena[*pc][0] == 164)
		&& (arg_size[0] = T_DIR))
		arg_size[1] = vm->arena[*pc][0] == 148 ? T_REG : T_DIR;
	else if ((vm->arena[*pc][0] == 212 || vm->arena[*pc][0] == 228)
		&& (arg_size[0] = T_IND))
		arg_size[1] = vm->arena[*pc][0] == 212 ? T_REG : T_DIR;
	if (ft_arg(vm, pc, arg_value, arg_size))
		if (vm->arena[save][0] == 54 || vm->arena[save][0] == 100
			|| vm->arena[save][0] == 148 || vm->arena[save][0] == 164
			|| vm->arena[save][0] == 212 || vm->arena[save][0] == 228)
		{
			exec_ldi(vm, arg_value);
			ft_visu_d_message(vm, "ldi");
}
}
