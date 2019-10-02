/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:11:05 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 16:45:00 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		tab_opcode_set(tab_opcode tab_opcode[17])
{
	tab_opcode[0] = 0;
	tab_opcode[1] = &op_live;
	tab_opcode[2] = &op_ld;
	tab_opcode[3] = &op_st;
	tab_opcode[4] = &op_add;
	tab_opcode[5] = &op_sub;
	tab_opcode[6] = &op_and;
	tab_opcode[7] = &op_or;
	tab_opcode[8] = &op_xor;
	tab_opcode[9] = &op_zjmp;
	tab_opcode[10] = &op_ldi;
	tab_opcode[11] = &op_sti;
	tab_opcode[12] = &op_fork;
	tab_opcode[13] = &op_lld;
	tab_opcode[14] = &op_lldi;
	tab_opcode[15] = &op_lfork;
	tab_opcode[16] = &op_aff;
}

void		tab_wait_set(t_vm *vm)
{
	vm->tab_wait[0] = 1;
	vm->tab_wait[1] = 10;
	vm->tab_wait[2] = 5;
	vm->tab_wait[3] = 5;
	vm->tab_wait[4] = 10;
	vm->tab_wait[5] = 10;
	vm->tab_wait[6] = 6;
	vm->tab_wait[7] = 6;
	vm->tab_wait[8] = 6;
	vm->tab_wait[9] = 20;
	vm->tab_wait[10] = 25;
	vm->tab_wait[11] = 25;
	vm->tab_wait[12] = 800;
	vm->tab_wait[13] = 10;
	vm->tab_wait[14] = 50;
	vm->tab_wait[15] = 1000;
	vm->tab_wait[16] = 2;
}

void		ft_wait(t_vm *vm, unsigned char opcode)
{
	vm->proc->opcode = opcode;
	if (opcode > 0 && opcode < 17)
		vm->proc->wait = vm->cycle + vm->tab_wait[opcode];
	else
	{
		vm->proc->pc = (vm->proc->pc + vm->tab_wait[0]) % MEM_SIZE;
		vm->proc->wait = vm->cycle + vm->tab_wait[0];
	}
}

void		ft_visu_wait(t_vm *vm)
{
	char	*str;

	if (vm->option_visu_d == 1)
	{
		wattron(vm->visu.hud, A_BOLD);
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 + vm->nb_champ
			* 4, 61, "                                         ");
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 + vm->nb_champ
			* 4, 61, "Need to wait : ");
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 + vm->nb_champ
			* 4, 77, (str = ft_itoa(vm->proc->wait - vm->cycle)));
		ft_strdel(&str);
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 + vm->nb_champ
			* 4, 78 + ft_strlen((str = ft_itoa(vm->proc->wait - vm->cycle))),
			"cycles.");
		ft_strdel(&str);
		wrefresh(vm->visu.hud);
	}
}
