/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:20 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 10:33:38 by anmauffr         ###   ########.fr       */
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

static void	new_process(t_proc **new)
{
	while ((*new)->next)
		(*new) = (*new)->next;
	if (!((*new)->next = malloc(sizeof(t_proc))))
		ft_error(ERROR_MALLOC, -1);
	(*new) = (*new)->next;
	(*new)->next = NULL;
}

/*
** PAS ENCORE FAIT MAIS JUSTE RAJOUTER UN CHAMP DANS LA STRUCT DE LA VM
** AVEC IDX_MOD SUR LES ADRESSES
*/

static void	exec_fork(t_vm *vm, unsigned int arg_value)
{
	int		i;
	t_proc	*new;

	new = vm->proc;
	new_process(&new);
	new->alive = vm->proc->alive;
	new->carry = vm->proc->carry;
	new->head = vm->proc->head;
	new->n_champ = vm->proc->n_champ;
	new->pc = arg_value < IDX_MOD ? vm->proc->pc - T_DIR + arg_value
		: vm->proc->pc - T_DIR - (arg_value % IDX_MOD);
	new->pc = new->pc > MEM_SIZE ? new->pc % MEM_SIZE : new->pc;
	new->pc = new->pc < 0 ? MEM_SIZE - new->pc % MEM_SIZE : new->pc;
	i = -1;
	while (++i < 16)
		new->r[i] = vm->proc->r[i];
	new->wait = vm->proc->wait + 1;
	new->during_fork = 1;
}

void		op_fork(t_vm *vm, int *pc)
{
	unsigned int	arg_value;

	ft_arg(vm, pc, &arg_value);
	exec_fork(vm, arg_value);
}
