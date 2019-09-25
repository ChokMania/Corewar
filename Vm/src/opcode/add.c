/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:59 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/25 12:28:58 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	int		i;

	i = 0;
	while (i < 3 && ((*pc) += T_REG))
		arg_value[i++] = vm->arena[*pc][0] - 0x01;
}

static void	exec_add(t_vm *vm, unsigned int arg_value[3])
{
	if (arg_value[0] <= 15 && arg_value[1] <= 15 && arg_value[2] <= 15)
	vm->proc->r[arg_value[2]] = vm->proc->r[arg_value[0]]
		+ vm->proc->r[arg_value[1]];
	vm->proc->carry = vm->proc->r[arg_value[2]] == 0 ? 1 : 0;
}

void		op_add(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];

	ft_arg(vm, pc, arg_value);
	exec_add(vm, arg_value);
	ft_visu_d_message(vm, "add");
}
