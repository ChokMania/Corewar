/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:24:51 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/17 13:37:35 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_REG SIZE 1
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value)
{
	(*pc) += T_REG;
	arg_value[0] = vm->arena[*pc][0] - 0x01;
}

static void	exec_aff(t_vm *vm, unsigned int arg_value[3])
{
	vm->option_visu == 0 ? ft_printf("%c", vm->proc->r[arg_value[0]] % 256) : 0;
}

void		op_aff(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];

	ft_arg(vm, pc, arg_value);
	exec_aff(vm, arg_value);
}
