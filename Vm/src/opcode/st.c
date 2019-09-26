/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:13 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/26 16:51:50 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_arg(t_vm *vm, unsigned int *pc, unsigned int *arg_value,
	unsigned int *arg_size)
{
	int		i;
	int		ret;

	i = -1;
	ret = 1;
	while (++i < 2)
		if (arg_size[i] == T_REG)
		{
			*pc = (*pc + T_REG) % MEM_SIZE;
			arg_size[i] = T_REG;
			arg_value[i] = vm->arena[*pc][0] - 0x01;
			if (arg_value[i] > 15)
				ret = 0;
		}
		else if (arg_size[i] == T_DIR)
		{
			*pc = (*pc + T_IND) % MEM_SIZE;
			arg_size[i] = T_DIR + 1;
			arg_value[i] = vm->arena[(*pc - 3) % MEM_SIZE][0] << 24
				| vm->arena[(*pc - 2) % MEM_SIZE][0] << 16 | vm->arena[(*pc - 1) % MEM_SIZE][0] << 8
				| vm->arena[*pc][0];
		}
		else if (arg_size[i] == T_IND)
		{
			*pc = (*pc + T_DIR) % MEM_SIZE;
			arg_size[i] = T_IND;
			arg_value[i] = vm->arena[(*pc - 1) % MEM_SIZE][0] << 8 | vm->arena[*pc][0];
		}
	return (ret);
}

static void	visual_st(t_vm *vm, int index)
{
	int		i;
	char	*str;

	i = 4;
	while (--i >= 0)
	{
		mvwprintw(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192),
			2 + ((3 * ((index + i) % MEM_SIZE)) % 192), (str = get_hexa(vm->arena[(index + i) % MEM_SIZE][0])));
		ft_strdel(&str);
		mvwchgat(vm->visu.arena, 1 + ((3 * ((index + i) % MEM_SIZE)) / 192), 2 +
			((3 * ((index + i) % MEM_SIZE)) % 192), 2, A_BOLD, vm->arena[(index + i) % MEM_SIZE][1], 0);
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
	unsigned int	size;

	if (!(index = 0) && arg_size[1] == T_REG)
		index += vm->proc->r[arg_value[0]] - T_REG;
	else if (arg_size[1] == T_IND)
		index += arg_value[1] - T_DIR;
	index += vm->proc->pc - 2;
	index %= MEM_SIZE;
	size = 2 + arg_size[1];
	/* NO IDX MOD*/
	if (arg_value[0] <= 15)
	{
		tmp = vm->proc->r[arg_value[0]];
		i = 5;
		while (--i >= 1)
		{
			vm->arena[(index + i - 1) % MEM_SIZE][0] = tmp % 256;
			vm->arena[(index + i - 1) % MEM_SIZE][1] = vm->proc->n_champ;
			tmp >>= 8;
		}
		vm->option_visu == 1 ? visual_st(vm, index) : 0;
	}
}


void		op_st(t_vm *vm, unsigned int *pc)
{
	unsigned int	arg_value[3];
	unsigned int	arg_size[3];
	int				save;

	*pc = (*pc + 1) % MEM_SIZE;
	save = *pc;
	arg_size[0] = T_REG;
	arg_value[2] = 0;
	arg_size[2] = 0;
	if (vm->arena[*pc][0] == 80)
		arg_size[1] = T_REG;
	else if (vm->arena[*pc][0] == 112)
		arg_size[1] = T_IND;
	if (ft_arg(vm, pc, arg_value, arg_size))
	{
		if (vm->arena[save][0] == 80 || vm->arena[save][0] == 112)
			exec_st(vm, arg_value, arg_size);
	}
}
