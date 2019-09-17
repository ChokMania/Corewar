/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:02:59 by judumay           #+#    #+#             */
/*   Updated: 2019/09/17 10:03:43 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	refresh_live_by_champ(t_vm *vm, int i)
{
	t_proc	*current;
	int		j;

	j = i;
	current = vm->beg;
	while (j-- > 0 && current)
		current = current->next;
	wattron(vm->visu.hud, A_BOLD);
	mvwprintw(vm->visu.hud, 19 + (i * 4), 40, ft_itoa(current->last_live));
	if (vm->nb_live_champ[i] == 0)
		mvwprintw(vm->visu.hud, 20 + (i * 4), 40, "0             ");
	else
		mvwprintw(vm->visu.hud, 20 + (i * 4), 40,
			ft_itoa(vm->nb_live_champ[i]));
	wattroff(vm->visu.hud, A_BOLD);
}

int		ft_round_sup(double to_round)
{
	int	round;
	int	x;

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

	i = -1;
	j = 0;
	total_live = 0;
	while (++i < vm->nb_champ && (total_live += vm->nb_live_champ[i]) >= 0)
		refresh_live_by_champ(vm, i);
	i = -1;
	tmp = 0;
	while (total_live != 0 && j < 100)
	{
		if (tmp == 0)
			tmp = ft_round_sup((vm->nb_live_champ[++i] * 100 / total_live));
		else
		{
			wattron(vm->visu.hud, COLOR_PAIR(i < vm->nb_champ ? i + 1 : 9));
			mvwprintw(vm->visu.hud, 20 + (vm->nb_champ * 4) + (barre * 3),
				6 + j++, "-");
			tmp--;
			wattroff(vm->visu.hud, COLOR_PAIR(i < vm->nb_champ ? i + 1 : 9));
		}
	}
}
