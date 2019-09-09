/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:59 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/06 14:25:30 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_REG SIZE 1
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		(*pc) += T_REG;
		arg_size[i] = T_REG;
		arg_value[i] = vm->arena[*pc][0] - 0x01;
	}
}

static void	exec_add(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	(void)arg_size;
	vm->proc->r[arg_value[2]] = vm->proc->r[arg_value[0]]
		+ vm->proc->r[arg_value[1]];
	vm->proc->carry = 1;
}

void		op_add(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	arg_size[0] = T_REG;
	arg_size[1] = T_REG;
	arg_size[2] = T_REG;
	ft_arg(vm, pc, arg_value, arg_size);
	exec_add(vm, arg_value, arg_size);
}
