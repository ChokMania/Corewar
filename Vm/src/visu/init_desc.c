/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:04:56 by judumay           #+#    #+#             */
/*   Updated: 2019/09/18 18:26:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_visu_d_message(t_vm *vm, char *str)
{
	if (vm->option_visu_d == 1)
	{
		wattron(vm->visu.hud, A_BOLD);
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 61, "                                         ");
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 61, "Effectue un ");
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 73, str);
		wrefresh(vm->visu.hud);
	}
}

void	init_description(t_vm *vm)
{
	int j;
	t_proc *current;

	j = -1;
	current = vm->beg;
	mvwprintw(vm->visu.hud, 26 + j * 2 + vm->nb_champ * 4, 50,
			"DERNIERE ACTION ENREGISTREE");
	while (++j < vm->nb_champ)
	{
		wattron(vm->visu.hud, COLOR_PAIR(j + 1));
		mvwprintw(vm->visu.hud, 26 + j * 2 + vm->nb_champ * 4, 40,
			ft_strsub(current->head.prog_name, 0, 10));
		mvwprintw(vm->visu.hud, 26 + j * 2 + vm->nb_champ * 4, 50 , "   : ");
		wattroff(vm->visu.hud, COLOR_PAIR((j + 1)));
		current = current->next;
	}
}

void	add_description(t_vm *vm)
{
	wattron(vm->visu.desc, A_BOLD);
	mvwprintw(vm->visu.desc, 1, 2, "add\t:");
	mvwprintw(vm->visu.desc, 2, 2, "aff\t:");
	mvwprintw(vm->visu.desc, 3, 2, "and\t:");
	mvwprintw(vm->visu.desc, 4, 2, "fork\t:");
	mvwprintw(vm->visu.desc, 5, 2, "ld\t:");
	mvwprintw(vm->visu.desc, 6, 2, "ldi\t:");
	mvwprintw(vm->visu.desc, 7, 2, "lfork\t:");
	mvwprintw(vm->visu.desc, 8, 2, "live\t:");
	mvwprintw(vm->visu.desc, 9, 2, "lld\t:");
	mvwprintw(vm->visu.desc, 10, 2, "lldi\t:");
	mvwprintw(vm->visu.desc, 11, 2, "or\t:");
	mvwprintw(vm->visu.desc, 12, 2, "st\t:");
	mvwprintw(vm->visu.desc, 13, 2, "sti\t:");
	mvwprintw(vm->visu.desc, 14, 2, "sub\t:");
	mvwprintw(vm->visu.desc, 15, 2, "xor\t:");
	mvwprintw(vm->visu.desc, 16, 2, "zjmp\t:");
	wattroff(vm->visu.desc, A_BOLD);
	wrefresh(vm->visu.desc);
}