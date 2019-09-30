/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:05:48 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/30 14:04:52 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_apply_proc(t_vm *vm)
{
	while (vm->proc)
	{
		if (vm->proc->wait == 0)
			ft_wait(vm, vm->arena[vm->proc->pc][0]);
		else
		{
			vm->proc->wait--;
			ft_visu_wait(vm);
			if (!vm->proc->wait)
			{
				ft_choise_opcode(vm, &vm->proc->pc, vm->proc->opcode);
				vm->proc->pc++;
				vm->proc->pc %= MEM_SIZE;
			}
		}
		vm->proc = vm->proc->next;
	}
}

static int ft_print_all(t_vm *vm)
{
	while (vm->proc)
	{
		ft_printf("name : %s, number : %d, alive : %d wait : %d creation : %d opcode: %hhd\n",
		vm->proc->head.prog_name, vm->proc->number, vm->proc->alive, vm->proc->wait,
		vm->proc->creation, vm->arena[vm->proc->pc][0]);
		vm->proc = vm->proc->next;
	}
	ft_printf("\n\ncycle : %d, cycle_to_die : %d\nlive zork: %d\tlive helltrain : %d\n",
	vm->cycle, vm->cycle_to_die, vm->nb_live_champ[0], vm->nb_live_champ[1]);
	exit (0);
}

void		ft_play(t_vm *vm)
{
	int		i;

	while (!(i = 0))
	{
		vm->option_dump > 0 && vm->option_dump == vm->cycle
			? ft_print_dump(*vm) : 0;
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
		vm->proc = vm->beg;
		ft_apply_proc(vm);
		vm->proc = vm->beg;
		vm->cycle++;
		vm->option_verbose == 2 && !vm->option_visu
		&& !vm->option_visu_d
		? ft_printf("It is now cycle %d\n", vm->cycle) : 0;
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
	ft_printf("\t\t\t\t- 0 : Show only essentials\n");
	ft_printf("\t\t\t\t- 1 : Show lives\n");
	ft_printf("\t\t\t\t- 2 : Show cycles\n");
	ft_printf("\t\t\t\t- 3 : Show death\n");
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
	if (vm.nb_champ < 1 || vm.nb_champ > 4)
		ft_error(ERROR_READ, -1, &vm);
	vm.option_visu == 1 ? ft_init_visu(&vm) : ft_introduce(&vm);
	ft_reverse_list(&vm.beg);
	vm.proc = vm.beg;
	ft_play(&vm);
	vm.option_visu == 1 ? endwin() : 0;
	return (0);
}
