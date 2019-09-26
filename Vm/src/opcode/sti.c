/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:25:16 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/26 12:30:03 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;
	int		r;

	i = -1;
	r = 1;
	while (++i < 3)
		if (arg_size[i] == T_REG)
		{
			(*pc) = (*pc + T_REG) % MEM_SIZE;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
			if (arg_value[i] > 15)
				r = 0;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) = (*pc + T_DIR) % MEM_SIZE;
			arg_size[i] = T_DIR;
			arg_value[i] = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8
				| vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) = (*pc + T_DIR) % MEM_SIZE;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[(*pc - 1 % MEM_SIZE)][0] << 8
				| vm->arena[*pc][0];
		}
	return (r);
}

static void	visual_sti(t_vm *vm, int index)
{
	int	i;

	i = 4;
	while (--i >= 0)
	{
		mvwprintw(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192),
			2 + ((3 * ((index + i) % MEM_SIZE)) % 192), get_hexa(vm->arena[(index + i) % MEM_SIZE][0]));
		mvwchgat(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192), 2 +
			((3 * ((index + i) % MEM_SIZE)) % 192), 2, A_BOLD, vm->arena[(index + i) % MEM_SIZE][1], 0);
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

/* CHECKER ARG VALUE*/
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
	if (index < vm->proc->pc - size && vm->proc->pc - size - index > IDX_MOD)
		index = vm->proc->pc - size - (vm->proc->pc - size - index) % IDX_MOD;
	else if (index > vm->proc->pc - size && index - (vm->proc->pc - size) >= IDX_MOD)
		index = vm->proc->pc - size + (index % IDX_MOD);
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
	int				save;

	(*pc)++;
	(*pc) %= MEM_SIZE;
	save = *pc;
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
	if (ft_arg(vm, pc, arg_value, arg_size))
		if (vm->arena[save][0] == 84 || vm->arena[save][0] == 88
		|| vm->arena[save][0] == 100 || vm->arena[save][0] == 104
		|| vm->arena[save][0] == 116 || vm->arena[save][0] == 120)
			exec_sti(vm, arg_value, arg_size);
}
