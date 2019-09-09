/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:05:48 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 17:59:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** LE CENTRE PRINCIPALE
** UN TOUR DANS LE GRAND WHILE == UN CYCLE EFFECTUE
**
** LES DEUX CHOSES QUE J'AI BALISE SERT A L'AFFICHAGE EXCLUSIVEMENT
**
** LE WHILE DANS LE GROD WHILE SERT A ORIENTER VERS OPCODE OU WAIT (OU AFFICHAGE)
**
** LES TROIS DERNIERS LIGNES SERVENT A ORIENTER VERS CYCLE TO DIE A LA FIN D'UN
** CYCLE SI BESOIN ET ENFIN AJOUTER UN CYCLE AU COMPTEUR DE CYCLE
*/

void	ft_play(t_vm *vm)
{
	int		i;

	vm->beg = vm->proc;
	while (!(i = 0))
	{
		/************************* PRINT START *************************/
		if (vm->option_dump > 0 && vm->option_dump == vm->cycle)
			ft_print_dump(*vm);
		// if (vm->cycle == 832)
		// {
		// 	ft_print_vm(*vm);
		// 	exit (0);
		// }
		//  if (vm->option_visu != 0)
		// 	while (vm->proc)
		// 	{
		// 		if (vm->proc->wait == 0)
		// 		{
		// 			ft_print_vm(*vm);
		// 			break ;
		// 		}
		// 		vm->proc = vm->proc->next;
		// 	}
		vm->proc = vm->beg;
		/*************************  PRINT END  *************************/
		while (vm->proc)
		{
			if (vm->proc->wait == 0)
				ft_wait(vm, vm->arena[vm->proc->pc][0]);
			else
			{
				vm->proc->wait--;
				if (vm->proc->during_fork == 1)
					vm->proc->during_fork = 0;
				else if (!vm->proc->wait)
				{
					ft_choise_opcode(vm, &vm->proc->pc, vm->arena[vm->proc->pc][0]);
					vm->proc->pc++;
				}
			}
			vm->proc = vm->proc->next;
			i++;
		}
		//if (vm->cycle > 0 && (vm->cycle - vm->total_to_die) % vm->cycle_to_die == 0)
		//	ft_cycle_to_die(vm);
		vm->proc = vm->beg;
		if (vm->option_visu == 1)
		{
			refresh_pc(vm);
			refresh_process(vm);
			visual_every_cycle(vm);
		}
		vm->cycle++;
	}
}

/*
** TMP FUNCTION FOR FREE CHAINE
*/

void	free_chaine(t_proc *proc)
{
	if (proc->next)
		free_chaine(proc->next);
	free(proc);
}

/*
** TMP FONCTION PRINT "FIN" AT END OF EXEC
**
** UN MAIN CLASSIQUE QUI SERT A ORIENTE UN PEU TOUT
*/

int		main(int ac, char **av)
{
	t_vm	vm;
	char	*tab[5];

	bzero(tab, sizeof(char*) * 5);
	bzero(&vm, sizeof(t_vm));
	vm.option_verbose = -1;
	if (ac == 1)
	{
		ft_printf("Usage : ./corewar (-d/-dump N) [[-n N] <champion1.cor>] <...>\n\n");
		ft_printf("\t-d/-dump N    : Dumps memory after N(int >= 0) cycles then exit the program\n");
		ft_printf("\t-n/-number N  : Give to champion(s) N(int > 0) player number\n");
		exit(0);
	}
	ft_args(ac, av, &vm, tab);
	ft_init_vm(&vm);
	ft_parsing(&vm, tab);
	vm.option_visu == 1 ? ft_init_visu(&vm) : ft_introduce(&vm);
	ft_play(&vm);
	vm.option_visu == 1 ? endwin() : 0;
	return (ft_printf(BOLD GRE"Fin\n"DEF));
}
