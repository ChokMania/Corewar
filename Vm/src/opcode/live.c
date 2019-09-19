/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:22:14 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/19 17:35:14 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value)
{
	(*pc) += T_IND;
	(*arg_value) = vm->arena[*pc - 3][0] << 24 | vm->arena[*pc - 2][0] << 16
		| vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
}

static void	exec_live(t_vm *vm, unsigned int arg_value)
{
	int		i;
	t_proc	*current;

	current = vm->beg;
	vm->proc->alive++;
	i = 1;
	while (i <= 4 && vm->nb_champ >= i && arg_value != UINT32_MAX - i + 1)
		i++;
	if (i < 5)
	{
		vm->nb_live_champ[i - 1]++;
		while (current && (int)current->n_champ != i)
			current = current->next;
		if (current && i == (int)current->n_champ)
		{
			current->last_live = vm->cycle;
			if (vm->option_verbose >= 1 && vm->option_verbose <= 2
				&& !vm->option_visu && !vm->option_visu_d)
				ft_printf("Player %u (%s) is said to be alive\n",
			current->n_champ, current->head.prog_name);
		}
	}
}

void		op_live(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_live(vm, arg_value);
	ft_visu_d_message(vm, "live");
}
