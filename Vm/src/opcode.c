/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:11:05 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/19 14:02:14 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** LA SUITE POUR L'ORIENTATION DE L'EXECUTION DE L'OPCODE APRES LE WAIT
*/

static void	ft_choise_opcode_suite(t_vm *vm, unsigned int *pc,
	unsigned char opcode)
{
	if (opcode == 10)
		op_ldi(vm, pc);
	else if (opcode == 11)
		op_sti(vm, pc);
	else if (opcode == 12)
		op_fork(vm, pc);
	else if (opcode == 13)
		op_lld(vm, pc);
	else if (opcode == 14)
		op_lldi(vm, pc);
	else if (opcode == 15)
		op_lfork(vm, pc);
	else if (opcode == 16)
		op_aff(vm, pc);
}

void		ft_choise_opcode(t_vm *vm, unsigned int *pc, unsigned char opcode)
{
	if (opcode == 1)
		op_live(vm, pc);
	else if (opcode == 2)
		op_ld(vm, pc);
	else if (opcode == 3)
		op_st(vm, pc);
	else if (opcode == 4)
		op_add(vm, pc);
	else if (opcode == 5)
		op_sub(vm, pc);
	else if (opcode == 6)
		op_and(vm, pc);
	else if (opcode == 7)
		op_or(vm, pc);
	else if (opcode == 8)
		op_xor(vm, pc);
	else if (opcode == 9)
		op_zjmp(vm, pc);
	else
		ft_choise_opcode_suite(vm, pc, opcode);
}

static void	ft_wait_suite(t_vm *vm, unsigned char opcode)
{
	if (opcode == 10)
		vm->proc->wait = 24;
	else if (opcode == 11)
		vm->proc->wait = 24;
	else if (opcode == 12)
		vm->proc->wait = 799;
	else if (opcode == 13)
		vm->proc->wait = 9;
	else if (opcode == 14)
		vm->proc->wait = 49;
	else if (opcode == 15)
		vm->proc->wait = 999;
	else if (opcode == 16)
		vm->proc->wait = 1;
	else
	{
		vm->proc->pc++;
		vm->proc->pc == MEM_SIZE ? vm->proc->pc = 0 : 0;
	}
}

/*
** FONCTION POUR WAIT AVANT L'EXECUTION DE L'OPCODE
*/

void		ft_wait(t_vm *vm, unsigned char opcode)
{
	if (opcode == 1)
		vm->proc->wait = 9;
	else if (opcode == 2)
		vm->proc->wait = 4;
	else if (opcode == 3)
		vm->proc->wait = 4;
	else if (opcode == 4)
		vm->proc->wait = 9;
	else if (opcode == 5)
		vm->proc->wait = 9;
	else if (opcode == 6)
		vm->proc->wait = 5;
	else if (opcode == 7)
		vm->proc->wait = 5;
	else if (opcode == 8)
		vm->proc->wait = 5;
	else if (opcode == 9)
		vm->proc->wait = 19;
	else
		ft_wait_suite(vm, opcode);
	ft_visu_wait(vm);
}

void		ft_visu_wait(t_vm *vm)
{
	if (vm->option_visu_d == 1)
	{
		wattron(vm->visu.hud, A_BOLD);
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 61, "                                         ");
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 61, "Need to wait : ");
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 77, ft_itoa(vm->proc->wait));
		mvwprintw(vm->visu.hud, 26 + (vm->proc->n_champ - 1) * 2 +
			vm->nb_champ * 4, 78 + ft_strlen(ft_itoa(vm->proc->wait)),
			"cycles.");
		wrefresh(vm->visu.hud);
	}
}
