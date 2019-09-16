/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:24:51 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/16 09:58:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_REG SIZE 1
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	(*pc) += T_REG;
	arg_size[0] = T_REG;
	arg_value[0] = vm->arena[*pc][0] - 0x01;
}

static void	exec_aff(t_vm *vm, unsigned int arg_value[3]
	, unsigned int arg_size[3])
{
	(void)arg_size;
	ft_printf("%c", vm->proc->r[arg_value[0]] % 256);
}

void		op_aff(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	arg_size[0] = T_REG;
	arg_size[1] = 0;
	arg_value[1] = 0;
	arg_size[2] = 0;
	arg_value[2] = 0;
	ft_arg(vm, pc, arg_value, arg_size);
	exec_aff(vm, arg_value, arg_size);
}
