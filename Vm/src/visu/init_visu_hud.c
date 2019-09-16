/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu_hud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:02:29 by judumay           #+#    #+#             */
/*   Updated: 2019/09/16 12:21:44 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_player_hud(t_vm *vm, int *i)
{
	while ((*i) < vm->nb_champ)
	{
		mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 5, "Player   :");
		mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 12, ft_itoa((*i) + 1));
		wattron(vm->visu->hud, COLOR_PAIR((*i) + 1));
		if (ft_strlen(vm->proc->head.prog_name) >= 120)
			mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 18,
			ft_strsub(vm->proc->head.prog_name, 0, 92));
		else
			mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 18,
				vm->proc->head.prog_name);
		wattroff(vm->visu->hud, COLOR_PAIR(((*i) + 1)));
		mvwprintw(vm->visu->hud, 19 + ((*i) * 4), 7, "Last live :\t\t\t0");
		mvwprintw(vm->visu->hud, 20 + ((*i) * 4), 7
		, "live in current period :\t\t0");
		(*i)++;
		vm->proc = vm->proc->next;
	}
	vm->proc = vm->beg;
	mvwprintw(vm->visu->hud, 19 + ((*i) * 4), 35
		, "Live breakdown for current period :");
	mvwprintw(vm->visu->hud, 22 + ((*i) * 4), 37
		, "Live breakdown for last period :");
	wattroff(vm->visu->hud, A_BOLD);
}

void	refresh_cycle_to_die(t_vm *vm)
{
	wattron(vm->visu->hud, A_BOLD);
	mvwprintw(vm->visu->hud, 26 + (vm->nb_champ * 4), 0,
	"                                                                 ");
	mvwprintw(vm->visu->hud, 26 + (vm->nb_champ * 4), 5, "CYCLE TO DIE :");
	mvwprintw(vm->visu->hud, 26 + (vm->nb_champ * 4), 20,
		ft_itoa(vm->cycle_to_die));
	wattroff(vm->visu->hud, A_BOLD);
}

void	write_infos_hud(t_vm *vm, int i)
{
	mvwprintw(vm->visu->hud, 26 + (i * 4), 5, "CYCLE TO DIE :");
	mvwprintw(vm->visu->hud, 26 + (i * 4), 20, ft_itoa(vm->cycle_to_die));
	mvwprintw(vm->visu->hud, 28 + (i * 4), 5, "CYCLE_DELTA :");
	mvwprintw(vm->visu->hud, 28 + (i * 4), 20, ft_itoa(CYCLE_DELTA));
	mvwprintw(vm->visu->hud, 30 + (i * 4), 5, "NBR_LIVE :");
	mvwprintw(vm->visu->hud, 30 + (i * 4), 20, ft_itoa(NBR_LIVE));
	mvwprintw(vm->visu->hud, 32 + (i * 4), 5, "NBR_CHECKS :");
	mvwprintw(vm->visu->hud, 32 + (i * 4), 20, ft_itoa(MAX_CHECKS));
	mvwprintw(vm->visu->hud, 46 + (i * 4), 5, "P : Cycle par Cycle             "
	"     Space : Play/Pause");
	mvwprintw(vm->visu->hud, 48 + (i * 4), 5, "M : Monter le nb de cycle       "
	"     N : Descend le nb de cycle (par 100)");
	mvwprintw(vm->visu->hud, 50 + (i * 4), 5, "R : Monter le nb de cycle       "
	"     Q : Descend le nb de cycle (par 10)");
	mvwprintw(vm->visu->hud, 52 + (i * 4), 5, "E : Monter le nb de cycle       "
	"     W : Descend le nb de cycle (par 1)");
	wrefresh(vm->visu->hud);
}

void	init_visual_hud(t_vm *vm)
{
	int		i;

	i = 0;
	wattron(vm->visu->hud, A_BOLD);
	mvwprintw(vm->visu->hud, 5, 45, "**   PAUSE   **");
	mvwprintw(vm->visu->hud, 11, 5, "Cycle/second limit : 50");
	mvwprintw(vm->visu->hud, 13, 5, "Cycle : 0");
	mvwprintw(vm->visu->hud, 15, 5, "Processes :");
	mvwprintw(vm->visu->hud, 15, 17, ft_itoa(vm->nb_champ));
	create_player_hud(vm, &i);
	mvwprintw(vm->visu->hud, 20 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(vm->visu->hud, 20 + (i * 4), 56
	, "--------------------------------------------------]");
	mvwprintw(vm->visu->hud, 23 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(vm->visu->hud, 23 + (i * 4), 56
	, "--------------------------------------------------]");
	wattron(vm->visu->hud, A_BOLD);
	write_infos_hud(vm, i);
	wrefresh(vm->visu->hud);
}
