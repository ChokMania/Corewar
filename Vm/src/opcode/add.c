/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:59 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/26 13:29:27 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	int		i;
	int		err;

	i = 0;
	err = 1;
	while (i < 3)
	{
		(*pc) = (*pc + T_REG) % MEM_SIZE;
		arg_value[i] = vm->arena[*pc][0] - 0x01;
		if (arg_value[i++] > 15)
			err = 0;
	}
	return (err);
}

static void	exec_add(t_vm *vm, unsigned int arg_value[3])
{
	t_proc	*proc;

	proc = vm->proc;
	proc->r[arg_value[2]] = proc->r[arg_value[0]] + proc->r[arg_value[1]];
	proc->carry = proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_add(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];

	if (ft_arg(vm, pc, arg_value))
	{
		exec_add(vm, arg_value);
		ft_visu_d_message(vm, "add");
	}
}
