/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:13 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/17 12:52:44 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** T_REG SIZE 1
** T_IND SIZE 2
** T_DIR SIZE 4
*/

static void	ft_arg(t_vm *vm, int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;

	i = -1;
	while (++i < 2)
		if (arg_size[i] == T_REG)
		{
			(*pc) += T_REG;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
		}
		else if (arg_size[i] == T_DIR)
		{
			(*pc) += T_IND;
			arg_size[i] = T_DIR + 1;
			arg_value[i] = vm->arena[*pc - 3][0] << 24
				| vm->arena[*pc - 2][0] << 16 | vm->arena[*pc - 1][0] << 8
				| vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			(*pc) += T_DIR;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[*pc - 1][0] << 8 | vm->arena[*pc][0];
		}
}

static void	exec_st(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	int		i;
	int		pc;
	int		tmp;

	pc = vm->proc->pc - 2;
	if (((arg_size[1] == T_REG && pc + vm->proc->r[arg_value[1]] >= MEM_SIZE)
		|| (arg_size[1] == T_IND && pc + arg_value[1] >= MEM_SIZE)))
		pc -= arg_size[1] == T_REG && pc + vm->proc->r[arg_value[1]] >= MEM_SIZE
			? IDX_MOD - vm->proc->r[arg_value[1]] % IDX_MOD + 1 :
			IDX_MOD - arg_value[1] % IDX_MOD + 2;
	else
		pc += arg_size[1] == T_REG ? vm->proc->r[arg_value[1]] % IDX_MOD - 1
			: arg_value[1] % IDX_MOD - 2;
	pc >= MEM_SIZE ? pc %= MEM_SIZE : 0;
	pc < 0 ? pc = MEM_SIZE + pc % MEM_SIZE : 0;
	i = 4;
	tmp = vm->proc->r[arg_value[0]];
	while (--i >= 0)
	{
		vm->arena[pc + i][0] = tmp % 256;
		vm->arena[pc + i][1] = vm->proc->n_champ;
		tmp >>= 8;
	}
}

static void	visual_st(t_vm *vm, unsigned int arg_value[3],
	unsigned int arg_size[3])
{
	int	i;
	int pc;

	pc = vm->proc->pc - 2;
	if ((i = 4) && ((arg_size[1] == T_REG && pc + vm->proc->r[arg_value[1]]
	>= MEM_SIZE) || (arg_size[1] == T_IND && pc + arg_value[1] >= MEM_SIZE)))
	{
		if (arg_size[1] == T_REG && pc + vm->proc->r[arg_value[1]] >= MEM_SIZE)
			pc -= IDX_MOD - vm->proc->r[arg_value[1]] % IDX_MOD + 1;
		else
			pc -= IDX_MOD - arg_value[1] % IDX_MOD + 2;
		pc %= MEM_SIZE;
	}
	else
	{
		if ((i = 4) && arg_size[1] == T_REG)
			pc += vm->proc->r[arg_value[1]] % IDX_MOD - 1;
		else
			pc += arg_value[1] % IDX_MOD - 2;
	}
	pc < 0 ? pc = MEM_SIZE + pc % MEM_SIZE : 0;
	while (--i >= 0)
	{
		mvwprintw(vm->visu.arena, 1 + ((3 * (pc + i)) / 192),
			2 + ((3 * (pc + i)) % 192), get_hexa(vm->arena[pc + i][0]));
		mvwchgat(vm->visu.arena, 1 + ((3 * (pc + i)) / 192),
			2 + ((3 * (pc + i)) % 192), 2, A_BOLD, vm->arena[pc + i][1], 0);
	}
	wrefresh(vm->visu.arena);
}

void		op_st(t_vm *vm, int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];

	(*pc)++;
	arg_size[0] = T_REG;
	arg_size[2] = 0;
	arg_value[2] = 0;
	if (vm->arena[*pc][0] == 80)
		arg_size[1] = T_REG;
	else if (vm->arena[*pc][0] == 112)
		arg_size[1] = T_IND;
	else
		ft_error(ERROR_ST, vm->proc->n_champ, vm);
	ft_arg(vm, pc, arg_value, arg_size);
	exec_st(vm, arg_value, arg_size);
	vm->option_visu == 1 ? visual_st(vm, arg_value, arg_size) : 0;
}
