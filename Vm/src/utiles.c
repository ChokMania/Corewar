/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:32:36 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 12:08:22 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** PRINT MAP
** PRINT HEADER OF BOTH CHAMPIONS
** TMP FONCTION
*/

void	ft_print_dump(t_vm vm)
{
	int		i;

	ft_printf("0x0000 : ");
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			ft_printf("\n%#.4x : ", i );
		ft_printf("%.2hhx ", vm.arena[i][0]);
	}
	ft_printf("\n");
	exit (0);
}

/*
** PRINT ARENA
*/

void	ft_print_vm(t_vm vm)
{
	int		i;

	i = 0;
	ft_printf("\033[H\033[2J");
	ft_printf("     ");
	while (++i < 65 * 2)
		if (i < 65 && ft_printf(YEL"%2d"DEF, i) && i < 64)
			ft_printf(" ");
		else if (i == 65)
			ft_printf("\n     --");
		else if (i > 66)
			ft_printf("---");
	i = -1;
	while (++i < MEM_SIZE)
	{
		while (vm.proc && vm.proc->pc != i)
			vm.proc = vm.proc->next;
		i % 64 == 0 ? ft_printf("\n"YEL"%2d"DEF" | ", i / 64 + 1) : ft_printf(" ");
		if (vm.proc && i == vm.proc->pc)
		{
			if (vm.proc->n_champ == 1)
				ft_printf(BACK_YEL BLU BOLD);
			else if (vm.proc->n_champ == 2)
				ft_printf(BACK_YEL RED BOLD);
			else if (vm.proc->n_champ == 3)
				ft_printf(BACK_YEL GRE BOLD);
			else if (vm.proc->n_champ == 4)
				ft_printf(BACK_YEL MAG BOLD);
		}
		else if (vm.arena[i][1] == 1)
			ft_printf(BACK_BLU BOLD);
		else if (vm.arena[i][1] == 2)
			ft_printf(BACK_RED BOLD);
		else if (vm.arena[i][1] == 3)
			ft_printf(BACK_GRE BOLD);
		else if (vm.arena[i][1] == 4)
			ft_printf(BACK_MAG BOLD);
		ft_printf("%.2hhx"DEF, vm.arena[i][0]);
		vm.proc = vm.beg;
	}
	i = -1;
	while (++i < vm.nb_champ)
		ft_printf("\n"BOLD"champ %d"DEF": %d lives", i + 1, vm.nb_live_champ[i]);
	ft_printf("\ncycle: %d\n", vm.cycle);
	sleep(1);
}

/*
** INVERT LES BYTES POUR LE MAGIC
*/

void	ft_invert_byte(unsigned int *val)
{
	int				i;
	unsigned int	revnbr;
	unsigned int	nbr;

	i = 3;
	nbr = *val;
	while (i >= 0)
	{
		((char*)(&revnbr))[i] = ((char*)(&nbr))[0];
		nbr = nbr >> 8;
		i--;
	}
	*val = revnbr;
}

/*
** INITIALISE TOUT LES CHAMPIONS/PROCESS ET LA STRUCT VM
*/

void	ft_init_vm(t_vm *vm)
{
	int		i;
	int		j;

	vm->total_to_die = 0;
	vm->nb_check_cycle = 0;
	i = -1;
	while (++i < MEM_SIZE && !(vm->arena[i][0] = 0))
		vm->arena[i][1] = 0;
	if (!(vm->proc = malloc(sizeof(t_proc))))
		ft_error(ERROR_MALLOC, -1);
	vm->beg = vm->proc;
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
				ft_error(ERROR_MALLOC, -1);
			vm->proc = vm->proc->next;
		}
	}
	vm->proc->next = NULL;
	vm->proc = vm->beg;
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
}

/*
** FONCTION QUI VERIFIE SI LE PROCESS A BIEN DIT QU'IL ETAIT EN VIE SINON LE TUE
** CETTE FONCTION PERMET EGALEMENT DE DETERMINER UN GAGNANT
*/

void	ft_cycle_to_die(t_vm *vm)
{
	int		i;

	vm->total_to_die += vm->cycle_to_die;
	vm->cycle_to_die -= CYCLE_DELTA;
	vm->nb_check_cycle++;
	while (vm->proc)
	{
		if (vm->proc->alive == 0)
			ft_dead_proc(vm);
		else if (vm->proc->alive < NBR_LIVE)
			;
		else if (vm->nb_live_champ[vm->proc->n_champ] < NBR_LIVE)
			ft_error(ERROR_NB_LIVE, vm->proc->n_champ);
		else
			vm->proc->alive = 0;
		vm->proc = vm->proc->next;
	}
	vm->proc = vm->beg;
	i = -1;
	while (++i < vm->nb_champ)
	{
		while (vm->proc && vm->proc->n_champ != (unsigned int)i)
			vm->proc = vm->proc->next;
		if (vm->proc)
		{
			ft_printf("Player %u (%s) is said to be alive (%u lives)\n",
				i + 1, vm->proc->head.prog_name, vm->nb_live_champ[i]);
			vm->nb_live_champ[i] = 0;
		}
		vm->proc = vm->beg;
	}
	ft_printf("\n");
}
