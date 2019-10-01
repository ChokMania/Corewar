/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:16 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/01 11:19:26 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	visual_sti(t_vm *vm, int index)
{
	int	i;

	i = 4;
	while (--i >= 0)
	{
		mvwprintw(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192),
			2 + ((3 * ((index + i) % MEM_SIZE)) % 192),
			get_hexa(vm->arena[(index + i) % MEM_SIZE][0]));
		mvwchgat(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192), 2 +
			((3 * ((index + i) % MEM_SIZE)) % 192), 2, A_BOLD,
			vm->arena[(index + i) % MEM_SIZE][1], 0);
	}
	wrefresh(vm->visu.arena);
	ft_visu_d_message(vm, "sti");
}

static void	exec_sti(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	tmp;
	unsigned int	size;

	if (!(index = 0) && arg_size[1] == T_REG)
		index += vm->proc->r[arg_value[1]] - T_REG;
	else if (arg_size[1] == T_DIR || arg_size[1] == T_IND)
		index += arg_value[1] - T_DIR;
	if (arg_size[2] == T_REG)
		index += vm->proc->r[arg_value[2]] - T_REG;
	else if (arg_size[2] == T_DIR)
		index += arg_value[2] - T_DIR;
	index += vm->proc->pc - 2;
	index %= MEM_SIZE;
	size = 2 + arg_size[1] + arg_size[2];
	//if (arg_size[2] == T_REG)
		// store dans un regsitre
	// if (index < vm->proc->pc - size && vm->proc->pc - size - index > IDX_MOD)
	// 	index = vm->proc->pc - size - (vm->proc->pc - size - index) % IDX_MOD;
	// else if (index > vm->proc->pc - size
	// 	&& index - (vm->proc->pc - size) >= IDX_MOD)
	// 	index = vm->proc->pc - size + (index % IDX_MOD);
	tmp = vm->proc->r[arg_value[0]];
	i = 5;
	while (--i >= 1)
	{
		vm->arena[(index + i - 1) % MEM_SIZE][0] = tmp % 256;
		vm->arena[(index + i - 1) % MEM_SIZE][1] = vm->proc->n_champ;
		tmp >>= 8;
	}
	vm->option_visu == 1 ? visual_sti(vm, index) : 0;
}

void		op_sti(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;
	int				opcode[2];

	opcode[0] = 2;
	opcode[1] = 2;
	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, opcode, 3) % MEM_SIZE;
	if (ft_opcode(vm, pc, arg_value, arg_size, opcode)
	&& arg_size[0] == T_REG
	&& (arg_size[1] == T_REG || arg_size[1] == T_DIR || arg_size[1] == T_IND)
	&& (arg_size[2] == T_REG || arg_size[2] == T_DIR))
		exec_sti(vm, arg_value, arg_size);
	else
		*pc = jump;
}
