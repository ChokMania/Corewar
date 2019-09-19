/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:02:35 by judumay           #+#    #+#             */
/*   Updated: 2019/09/19 14:33:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_victory_visu(t_vm *vm, t_proc *winner)
{
	vm->visu.winner = newwin(18, 111, 66, 195);
	box(vm->visu.winner, 0, 0);
	//wattron(vm->visu.winner, COLOR_PAIR(winner->n_champ));
	mvwprintw(vm->visu.winner, 2, 20,
	" /$$      /$$ /$$$$$$ /$$   /$$ /$$   /$$ /$$$$$$$$ /$$$$$$$ ");
	mvwprintw(vm->visu.winner, 3, 20,
	"| $$  /$ | $$|_  $$_/| $$$ | $$| $$$ | $$| $$_____/| $$__  $$");
	mvwprintw(vm->visu.winner, 4, 20,
	"| $$ /$$$| $$  | $$  | $$$$| $$| $$$$| $$| $$      | $$  \\ $$");
	mvwprintw(vm->visu.winner, 5, 20,
	"| $$/$$ $$ $$  | $$  | $$ $$ $$| $$ $$ $$| $$$$$   | $$$$$$$/");
	mvwprintw(vm->visu.winner, 6, 20,
	"| $$$$_  $$$$  | $$  | $$  $$$$| $$  $$$$| $$__/   | $$__  $$");
	mvwprintw(vm->visu.winner, 7, 20,
	"| $$$/ \\  $$$  | $$  | $$\\  $$$| $$\\  $$$| $$      | $$  \\ $$");
	mvwprintw(vm->visu.winner, 8, 20,
	"| $$/   \\  $$ /$$$$$$| $$ \\  $$| $$ \\  $$| $$$$$$$$| $$  | $$");
	mvwprintw(vm->visu.winner, 9, 20,
	"|__/     \\__/|______/|__/  \\__/|__/  \\__/|________/|__/  |__/");
	mvwprintw(vm->visu.winner, 10, 20,
	"                                                             ");
	mvwprintw(vm->visu.winner, 11, 20, winner->head.prog_name);
	wrefresh(vm->visu.winner);
	//wattroff(vm->visu.winner, COLOR_PAIR(winner->n_champ));
	sleep(2);
	endwin();
	ft_printf("%s\n", winner->head.prog_name);
	free_chaine(vm->beg);
	exit (0);
}

void	refresh_pc(t_vm *vm)
{
	t_proc	*pr;

	pr = vm->beg;
	while (pr)
	{
		mvwchgat(vm->visu.arena, 1 + ((pr->pc * 3) / 192)
		, 2 + ((pr->pc * 3) % 192), 2, A_REVERSE
		, vm->arena[pr->pc][1], 0);
		pr = pr->next;
	}
	wrefresh(vm->visu.arena);
	pr = vm->beg;
	while (pr)
	{
		if (vm->arena[pr->pc][1] == 0)
			mvwchgat(vm->visu.arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_BOLD
			, 10, 0);
		else
			mvwchgat(vm->visu.arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_BOLD
			, vm->arena[pr->pc][1], 0);
		pr = pr->next;
	}
}

void	visual_every_cycle(t_vm *vm)
{
	wattron(vm->visu.hud, A_BOLD);
	mvwprintw(vm->visu.hud, 13, 13, ft_itoa(vm->cycle));
	wattroff(vm->visu.hud, A_BOLD);
	wrefresh(vm->visu.hud);
	get_key(vm);
}

int		ft_list_count_vm(t_proc *begin_list)
{
	int		i;
	t_proc	*current;

	i = 0;
	current = begin_list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	refresh_process(t_vm *vm)
{
	wattron(vm->visu.hud, A_BOLD);
	mvwprintw(vm->visu.hud, 15, 17, "      ");
	mvwprintw(vm->visu.hud, 15, 17, ft_itoa(ft_list_count_vm(vm->proc)));
	wattroff(vm->visu.hud, A_BOLD);
	wrefresh(vm->visu.hud);
}
