/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:22:14 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/16 13:37:01 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_DIR SIZE 4
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	(*pc) += T_IND;
	arg_size[0] = T_DIR + 1;
	arg_value[0] = vm->arena[*pc - 3][0] << 24 | vm->arena[*pc - 2][0] << 16
		| vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
}

/*
** PAS ENCORE COMPRIS L'ARG DEVANT LE LIVE
*/

static void	exec_live(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	(void)arg_size;
	(void)arg_value;
	vm->proc->alive++;
	vm->nb_live_champ[vm->proc->n_champ - 1]++;
	vm->proc->last_live = vm->cycle;
}

void		op_live(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	arg_size[0] = T_DIR;
	arg_size[1] = 0;
	arg_value[1] = 0;
	arg_size[2] = 0;
	arg_value[2] = 0;
	ft_arg(vm, pc, arg_value, arg_size);
	exec_live(vm, arg_value, arg_size);
	if (vm->option_verbose >= 0)
		ft_printf("Player %u (%s) is said to be alive\n",
			vm->proc->n_champ, vm->proc->head.prog_name);
}
