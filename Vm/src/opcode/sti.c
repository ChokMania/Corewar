/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:16 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/23 15:22:10 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;

	i = -1;
	while (++i < 3)
		if (arg_size[i] == T_REG)
		{
			(*pc) += T_REG;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) += T_DIR;
			arg_size[i] = T_DIR;
			arg_value[i] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) += T_DIR;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
		}
}

static void	visual_sti(t_vm *vm, int index)
{
	int	i;

	i = 4;
	while (--i >= 0)
	{
		mvwprintw(vm->visu.arena, 1 + ((3 * (index + i)) / 192),
			2 + ((3 * (index + i)) % 192), get_hexa(vm->arena[index + i][0]));
		mvwchgat(vm->visu.arena, 1 + ((3 * (index + i)) / 192), 2 +
			((3 * (index + i)) % 192), 2, A_BOLD, vm->arena[index + i][1], 0);
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

	if (!(index = 0) && arg_size[1] == T_REG)
		index += vm->proc->r[arg_value[1]] - T_REG;
	else if (arg_size[1] == T_DIR || arg_size[1] == T_IND)
		index += arg_value[1] - T_DIR;
	if (arg_size[2] == T_REG)
		index += vm->proc->r[arg_value[2]] - T_REG;
	else if (arg_size[2] == T_DIR)
		index += arg_value[2] - T_DIR;
	i = (vm->proc->pc - IDX_MOD) % MEM_SIZE;
	index += vm->proc->pc - 2;
	index %= MEM_SIZE;
	if (index < vm->proc->pc - 6 && vm->proc->pc - 6 - index > IDX_MOD)
		index = vm->proc->pc - 6 - (vm->proc->pc - 6 - index) % IDX_MOD;
	else if (index > vm->proc->pc - 6 && index - (vm->proc->pc - 6) >= IDX_MOD)
		index = vm->proc->pc - 6 + (index % IDX_MOD);
	tmp = vm->proc->r[arg_value[0]];
	i = 5;
	while (--i >= 1)
	{
		vm->arena[index + i - 1][0] = tmp % 256;
		vm->arena[index + i - 1][1] = vm->proc->n_champ;
		tmp >>= 8;
	}
	vm->option_visu == 1 ? visual_sti(vm, index) : 0;
}

void		op_sti(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				save;

	(*pc)++;
	save = pc;
	arg_size[0] = T_REG;
	if ((vm->arena[*pc][0] == 84 || vm->arena[*pc][0] == 88)
		&& (arg_size[1] = T_REG))
		arg_size[2] = vm->arena[*pc][0] == 84 ? T_REG : T_DIR;
	else if ((vm->arena[*pc][0] == 100 || vm->arena[*pc][0] == 104)
		&& (arg_size[1] = T_DIR))
		arg_size[2] = vm->arena[*pc][0] == 100 ? T_REG : T_DIR;
	else if ((vm->arena[*pc][0] == 116 || vm->arena[*pc][0] == 120)
		&& (arg_size[1] = T_IND))
		arg_size[2] = vm->arena[*pc][0] == 116 ? T_REG : T_DIR;
	ft_arg(vm, pc, arg_value, arg_size);
	if (vm->arena[save][0] == 84 || vm->arena[save][0] == 88
	|| vm->arena[save][0] == 100 || vm->arena[save][0] == 104
	|| vm->arena[save][0] == 116 || vm->arena[save][0] == 120)
		exec_sti(vm, arg_value, arg_size);
}
