/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:04 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/28 18:26:46 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (i < 3)
	{
		*pc = (*pc + T_REG) % MEM_SIZE;
		arg_value[i++] = vm->arena[*pc][0] - 0x01;
		if (arg_value[i] > 15)
			ret = 0;
	}
	return (ret);
}

static void	exec_sub(t_vm *vm, unsigned int arg_value[3])
{
	vm->proc->r[arg_value[2]] = vm->proc->r[arg_value[0]]
		- vm->proc->r[arg_value[1]];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_sub(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];

	if (ft_arg(vm, pc, arg_value))
	{
		exec_sub(vm, arg_value);
		ft_visu_d_message(vm, "sub");
	}
}
