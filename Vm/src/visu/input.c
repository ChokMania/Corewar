/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:59:21 by judumay           #+#    #+#             */
/*   Updated: 2019/09/16 12:25:54 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	modif_cps(t_vm *vm, int to_add)
{
	vm->visu->cps += to_add;
	if (vm->visu->cps > 1000)
		vm->visu->cps = 1000;
	else if (vm->visu->cps < 10)
		vm->visu->cps = 10;
	wattron(vm->visu->hud, A_BOLD);
	mvwprintw(vm->visu->hud, 11, 26, ft_itoa(vm->visu->cps));
	mvwprintw(vm->visu->hud, 11,
		26 + ft_strlen(ft_itoa(vm->visu->cps)), "    ");
	wrefresh(vm->visu->hud);
}

int		handle_pause(t_vm *vm, int *pause, int p_or_r)
{
	wattron(vm->visu->hud, A_BOLD);
	if (p_or_r == 1)
	{
		mvwprintw(vm->visu->hud, 5, 45, "**   PAUSE   **");
		(*pause) *= -1;
		wrefresh(vm->visu->hud);
	}
	else if (p_or_r == 2)
	{
		mvwprintw(vm->visu->hud, 5, 45, "**   PAUSE   **");
		(*pause) = 1;
		wrefresh(vm->visu->hud);
	}
	else
		mvwprintw(vm->visu->hud, 5, 45, "**  RUNNING  **");
	wattroff(vm->visu->hud, A_BOLD);
	return (1);
}

void	get_key(t_vm *vm)
{
	int			i;
	static int	pause = 1;

	while (1)
	{
		timeout(0);
		if ((i = getch()) == ' ')
			handle_pause(vm, &pause, 1);
		else if (i == 'p' && handle_pause(vm, &pause, 2))
			break ;
		else if (i == 'e' && vm->visu->cps < 1000)
			modif_cps(vm, 1);
		else if (i == 'r' && vm->visu->cps < 1000)
			modif_cps(vm, 10);
		else if (i == 'm' && vm->visu->cps < 1000)
			modif_cps(vm, 100);
		else if (i == 'w' && vm->visu->cps > 10)
			modif_cps(vm, -1);
		else if (i == 'q' && vm->visu->cps > 10)
			modif_cps(vm, -10);
		else if (i == 'n' && vm->visu->cps > 10)
			modif_cps(vm, -100);
		if (pause == -1 && handle_pause(vm, &pause, 0))
			break ;
	}
	timeout(1);
	usleep(1000000 / vm->visu->cps);
}
