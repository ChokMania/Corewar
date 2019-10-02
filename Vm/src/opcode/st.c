/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:13 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 12:31:05 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	visual_st(t_vm *vm, int index)
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
	ft_visu_d_message(vm, "st");
}

static void	exec_st(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	unsigned int	i;
	unsigned int	index;
	unsigned int	tmp;
	unsigned int	realpc;
	

	if (!(index = 0) && arg_size[1] == T_REG)
		index += vm->proc->r[arg_value[1]] - T_REG;
	else if (arg_size[1] == T_IND)
		index += arg_value[1] - T_DIR;
	index += vm->proc->pc - 2;
	realpc = (vm->proc->pc - arg_size[0] - arg_size[1]) % MEM_SIZE;
	index %= MEM_SIZE;
	//idx mode
	if ((index < realpc && realpc - index <= IDX_MOD) || (index > realpc && index - realpc <= IDX_MOD) || (index > realpc && realpc + MEM_SIZE - index <= IDX_MOD) || (index < realpc && index + MEM_SIZE - realpc <= IDX_MOD))
		;
	else if (index < realpc)
		index = realpc - (realpc - index) % IDX_MOD;
	else if (index > realpc)
		index = (realpc + (index % IDX_MOD) - 1) % MEM_SIZE;
	// fin idx mode
	//INVALID READ DE ST
	if (arg_size[1] == T_REG)
		vm->proc->r[arg_value[1]] = vm->proc->r[arg_value[0]];
	else
	{
		tmp = vm->proc->r[arg_value[0]];
		i = 5;
		while (--i >= 1)
		{
			vm->arena[(index + i - 1) % MEM_SIZE][0] = tmp % 256;
			vm->arena[(index + i - 1) % MEM_SIZE][1] = vm->proc->n_champ;
			tmp >>= 8;
		}
	}
	vm->option_visu == 1 ? visual_st(vm, index) : 0;
}

void		op_st(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				jump;

	(*pc) = (*pc + 1) % MEM_SIZE;
	jump = *pc;
	jump += recup_opc(vm->arena[*pc][0], arg_size, 4, 2) % MEM_SIZE;
	if (ft_opcode(vm, pc, arg_value, arg_size, 4)
	&& arg_size[0] == T_REG
	&& (arg_size[1] == T_REG || arg_size[1] == T_IND))
		exec_st(vm, arg_value, arg_size);
	else
		*pc = jump;
}
