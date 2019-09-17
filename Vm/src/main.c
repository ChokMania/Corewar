/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:05:48 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/17 10:39:45 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_apply_proc(t_vm *vm, int *i)
{
	while (vm->proc)
	{
		if (vm->proc->wait == 0)
			ft_wait(vm, vm->arena[vm->proc->pc][0]);
		else
		{
			vm->proc->wait--;
			ft_visu_wait(vm);
			if (vm->proc->during_fork == 1)
				vm->proc->during_fork = 0;
			else if (!vm->proc->wait)
			{
				ft_choise_opcode(vm, &vm->proc->pc, vm->arena[vm->proc->pc][0]);
				vm->proc->pc++;
			}
		}
		vm->proc = vm->proc->next;
		(*i)++;
	}
}

void		ft_play(t_vm *vm)
{
	int		i;

	vm->beg = vm->proc;
	while (!(i = 0))
	{
		if (vm->cycle > 0
			&& (vm->cycle - vm->total_to_die) % vm->cycle_to_die == 0)
			ft_cycle_to_die(vm);
		if (vm->option_visu == 1)
		{
			refresh_pc(vm);
			refresh_live(vm, 0);
			refresh_process(vm);
			visual_every_cycle(vm);
		}
		if (vm->option_dump > 0 && vm->option_dump == vm->cycle)
			ft_print_dump(*vm);
		ft_apply_proc(vm, &i);
		vm->proc = vm->beg;
		vm->cycle++;
	}
}

static void	ft_usage(void)
{
	ft_printf("Usage : ./corewar (-d/-dump N)"
	"[[-n N] <champion1.cor>] <...>\n\n");
	ft_printf("\t-d/-dump      N : Dumps memory after N(int >= 0) "
	"cycles then exit the program\n");
	ft_printf("\t-n/-number    N : Give to champion(s) N(int > 0) "
	"player number\n");
	ft_printf("\t-v/-verbose   N : Give more infos during match\n");
	ft_printf("\t-vi/-visual     : Give visual of the match\n");
	ft_printf("\t-vid/-visuald   : Add explication on the visual "
	"(ONLY 1 PROCESS BY CHAMPION)\n");
	exit(0);
}

int			main(int ac, char **av)
{
	t_vm	vm;
	char	*tab[5];

	bzero(tab, sizeof(char*) * 5);
	bzero(&vm, sizeof(t_vm));
	vm.option_verbose = -1;
	if (ac == 1)
		ft_usage();
	ft_args(ac, av, &vm, tab);
	ft_init_vm(&vm);
	ft_parsing(&vm, tab);
	vm.option_visu == 1 ? ft_init_visu(&vm) : ft_introduce(&vm);
	ft_play(&vm);
	vm.option_visu == 1 ? endwin() : 0;
	return (0);
}
