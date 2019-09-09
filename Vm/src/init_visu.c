/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:25:35 by judumay           #+#    #+#             */
/*   Updated: 2019/09/09 13:58:46 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	init_color_vm(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_RED);
	init_pair(7, COLOR_WHITE, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_BLACK);
}

void	ft_init_visu(t_vm *vm)
{
	int	i;

	i = 0;
	if (!(vm->visu = (t_visu*)malloc(sizeof(t_visu) * 1)))
		return ;
	initscr();
	noecho();
	timeout(500);
	curs_set(0);
	init_color_vm();
	vm->visu->arena = newwin(66, 195, 0, 0);
	vm->visu->hud = newwin(66, 111, 0, 195);
	vm->visu->str = 0;
	vm->visu->cps = 1;
	refresh();
	box(vm->visu->arena, 0, 0);
	box(vm->visu->hud, 0, 0);
	vm->visu->cps = 50;
	//init_champ_in_visu(vm, i);
	wrefresh(vm->visu->arena);
	//init_visual_hud(vm);
	sleep(1000000);
}
