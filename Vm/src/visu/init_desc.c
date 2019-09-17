/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:04:56 by judumay           #+#    #+#             */
/*   Updated: 2019/09/17 10:54:26 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_description(t_vm *vm)
{
	int j;
	t_proc *current;

	j = -1;
	current = vm->beg;
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