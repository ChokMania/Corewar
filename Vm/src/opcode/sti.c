/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:16 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/04 01:11:57 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			visual_sti(t_vm *vm, int index)
{
	int		i;
	char	*str;

	i = 4;
	while (--i >= 0)
	{
		mvwprintw(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192),
			2 + ((3 * ((index + i) % MEM_SIZE)) % 192),
			(str = get_hexa(vm->arena[(index + i) % MEM_SIZE][0])));
		ft_strdel(&str);
		mvwchgat(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192), 2 +
			((3 * ((index + i) % MEM_SIZE)) % 192), 2, A_BOLD,
			vm->arena[(index + i) % MEM_SIZE][1], 0);
	}
	wrefresh(vm->visu.arena);
	ft_visu_d_message(vm, "sti");
}

static unsigned int	exec_sti(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3], unsigned int index)
{
	unsigned int	i;
	unsigned int	tmp;

	if (!(index = 0) && arg_size[1] == T_REG)
		index += vm->proc->r[arg_value[1]];
	else if (arg_size[1] == T_DIR || arg_size[1] == T_IND)
		index += arg_value[1];
	if (arg_size[1] == T_IND)
		arg_size[1] = 2;
	if (arg_size[2] == T_REG)
		index += vm->proc->r[arg_value[2]];
	else if (arg_size[2] == T_DIR)
		index += arg_value[2];
	//index = idx_mod_16((vm->proc->pc - arg_size[0] - arg_size[1] - arg_size[2] - 1)
	//	% MEM_SIZE, index);
	tmp = vm->proc->r[arg_value[0]];
	i = 5;
	while (--i >= 1)
	{
		vm->arena[(index + i - 1) % MEM_SIZE][0] = tmp % 256;
		vm->arena[(index + i - 1) % MEM_SIZE][1] = vm->proc->n_champ;
		tmp >>= 8;
	}
	return (index);
}

void				op_sti(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	unsigned int	index;
	int				jump;

	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	index = 0;
	jump += recup_opc(vm->arena[*pc][0], arg_size, 2, 3) % MEM_SIZE;
	if (ft_opcode(vm, arg_value, arg_size, 2)
	&& arg_size[0] == T_REG
	&& (arg_size[1] == T_REG || arg_size[1] == T_DIR || arg_size[1] == T_IND)
	&& (arg_size[2] == T_REG || arg_size[2] == T_DIR))
	{
		index = exec_sti(vm, arg_value, arg_size, index);
		vm->option_visu == 1 ? visual_sti(vm, index) : 0;
	}
	else
		*pc = jump;
}
