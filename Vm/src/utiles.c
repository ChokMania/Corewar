/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:32:36 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/16 13:30:58 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_init_vm_suite(t_vm *vm)
{
	int i;
	int j;

	i = -1;
	while (++i < vm->nb_champ)
	{
		vm->proc->alive = 0;
		vm->proc->carry = 0;
		vm->proc->during_fork = 0;
		j = -1;
		while (++j < REG_NUMBER)
			vm->proc->r[j] = j == 0 ? 0xFFFFFFFF - i : 0;
		vm->nb_live_champ[i] = 0;
		vm->proc->wait = 0;
		if (i + 1 < vm->nb_champ)
		{
			if (!(vm->proc->next = malloc(sizeof(t_proc))))
				ft_error(ERROR_MALLOC, -1, vm);
			vm->proc = vm->proc->next;
		}
	}
}

void		ft_init_vm(t_vm *vm)
{
	int		i;

	vm->total_to_die = 0;
	vm->nb_check_cycle = 0;
	i = -1;
	while (++i < MEM_SIZE && !(vm->arena[i][0] = 0))
		vm->arena[i][1] = 0;
	if (!(vm->proc = malloc(sizeof(t_proc))))
		ft_error(ERROR_MALLOC, -1, vm);
	vm->beg = vm->proc;
	ft_init_vm_suite(vm);
	vm->proc->next = NULL;
	vm->proc = vm->beg;
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
}

static void	ft_winner(t_vm *vm)
{
	int		last;
	t_proc	*winner;
	t_proc	*current;

	current = vm->beg;
	winner = vm->beg;
	last = vm->beg->last_live;
	while (current)
	{
		if (last < current->last_live && (last = current->last_live))
			winner = current;
		current = current->next;
	}
	ft_printf("Contestant %d, \"%s\", has won ! at cycle %d\n",
		winner->n_champ, winner->head.prog_name, vm->cycle);
	free_chaine(vm->beg);
	exit(0);
}

static void	ft_cdt_suite(t_vm *vm)
{
	int		i;
	t_proc	*current;

	current = vm->beg;
	i = -1;
	if (vm->cycle_to_die == 0)
	{
		vm->cycle++;
		endwin();
		ft_winner(vm);
	}
	while (current)
	{
		current->alive == 0 ? ft_dead_proc(vm) : (current->alive = 0);
		current = current->next;
	}
	while (++i < vm->nb_champ)
		vm->nb_live_champ[i] = 0;
}

void		ft_cycle_to_die(t_vm *vm)
{
	int		i;
	t_proc	*current;

	i = 0;
	vm->nb_check_cycle++;
	current = vm->beg;
	while (current && ((i += current->alive) >= 0))
		current = current->next;
	vm->total_to_die += vm->cycle_to_die;
	if (i > NBR_LIVE || !(vm->nb_check_cycle % MAX_CHECKS))
	{
		vm->cycle_to_die = CYCLE_DELTA > vm->cycle_to_die
			? 0 : vm->cycle_to_die - CYCLE_DELTA;
		vm->nb_check_cycle = 0;
	}
	vm->option_visu == 1 ? refresh_cycle_to_die(vm) : 0;
	refresh_live(vm, 1);
	ft_cdt_suite(vm);
}
