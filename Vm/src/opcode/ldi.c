/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:30 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/28 16:22:43 by judumay          ###   ########.fr       */
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
			(*pc) = (*pc + T_REG) % MEM_SIZE;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
			if (arg_value[i] > 15)
				ret = 0;
		}
		else if (arg_size[i] == T_DIR || arg_size[i] == T_IND)
		{
			(*pc) = (*pc + T_DIR) % MEM_SIZE;
			arg_value[i] = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8
				| vm->arena[*pc][0];
		}
	return (0);
}

static void	exec_ldi(t_vm *vm, unsigned int arg_value[3])
{
	vm->proc->r[arg_value[2]] = (arg_value[0] + arg_value[1]) % IDX_MOD;
}

void		op_ldi(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	(*pc) = (*pc + 1) % MEM_SIZE;
	recup_opc(vm->arena[*pc][0], arg_size);
	if (ft_arg(vm, pc, arg_value, arg_size))
	{
		exec_ldi(vm, arg_value);
		ft_visu_d_message(vm, "ldi");
	}
}
