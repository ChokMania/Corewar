/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:12 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/16 10:34:24 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_DIR SIZE 2
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value)
{
	(*pc) += T_DIR;
	*arg_value = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
}

/*
** creation d'un nouveau process dans la liste des process
*/

static void	new_process(t_proc **new, t_vm *vm)
{
	while ((*new)->next)
		(*new) = (*new)->next;
	if (!((*new)->next = malloc(sizeof(t_proc))))
		ft_error(ERROR_MALLOC, -1, vm);
	(*new) = (*new)->next;
	(*new)->next = NULL;
}

/*
** PAS ENCORE FAIT MAIS JUSTE RAJOUTER UN CHAMP DANS LA STRUCT DE LA VM
*/

static void	exec_lfork(t_vm *vm, unsigned int arg_value)
{
	int		i;
	t_proc	*new;

	new = vm->proc;
	new_process(&new, vm);
	new->alive = vm->proc->alive;
	new->carry = vm->proc->carry;
	new->head = vm->proc->head;
	new->n_champ = vm->proc->n_champ;
	new->pc = vm->proc->pc - T_DIR + arg_value;
	new->pc = new->pc > MEM_SIZE ? new->pc % MEM_SIZE : new->pc;
	new->pc = new->pc < MEM_SIZE ? MEM_SIZE - new->pc % MEM_SIZE : new->pc;
	i = -1;
	while (++i < 16)
		new->r[i] = vm->proc->r[i];
	new->wait = vm->proc->wait + 1;
	new->during_fork = 1;
}

void		op_lfork(t_vm *vm, int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_lfork(vm, arg_value);
}
