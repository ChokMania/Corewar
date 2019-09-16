/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:02:59 by judumay           #+#    #+#             */
/*   Updated: 2019/09/16 12:19:28 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	refresh_live_by_champ(t_vm *vm, int i)
{
	//pas le bon last;
	wattron(vm->visu->hud, A_BOLD);
	mvwprintw(vm->visu->hud, 19 + (i * 4), 40, ft_itoa(vm->proc->last_live));
	if (vm->nb_live_champ[i] == 0)
		mvwprintw(vm->visu->hud, 20 + (i * 4), 40, "0             ");
	else
		mvwprintw(vm->visu->hud, 20 + (i * 4), 40, ft_itoa(vm->nb_live_champ[i]));
	wattroff(vm->visu->hud, A_BOLD);
}

int		ft_round_sup(double to_round)
{
	int round;
	int x;
	
	round = (int)to_round;
	to_round *= 10;
	x = (int)to_round;
	if (x > 0)
		round++;
	return (round);
}

void	refresh_live(t_vm *vm, int barre)
{
	int		i;
	int		j;
	double	tmp;
	int		total_live;

	i = 0;
	j = 0;
	total_live = 0;
	while (i < vm->nb_champ)
	{
		refresh_live_by_champ(vm, i);
		total_live += vm->nb_live_champ[i];
		i++;
	}
	i = -1;
	tmp = 0;
	if (total_live != 0)
		while (j < 100)
		{
			if (tmp == 0)
				tmp = ft_round_sup((vm->nb_live_champ[++i] * 100 / total_live));
			else
			{
				if (i < vm->nb_champ)
					wattron(vm->visu->hud, COLOR_PAIR(i + 1));
				else
					wattron(vm->visu->hud, COLOR_PAIR(9));
					mvwprintw(vm->visu->hud, 20 + (vm->nb_champ * 4) + (barre * 3), 6 + j++, "-");
					tmp--;
				if (i < vm->nb_champ)
					wattroff(vm->visu->hud, COLOR_PAIR(i + 1));
				else
					wattroff(vm->visu->hud, COLOR_PAIR(9));
			}
		}
}