/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:56:33 by judumay           #+#    #+#             */
/*   Updated: 2019/09/24 13:18:16 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_invert_byte(unsigned int *val)
{
	int				i;
	unsigned int	revnbr;
	unsigned int	nbr;

	i = 3;
	nbr = *val;
	while (i >= 0)
	{
		((char*)(&revnbr))[i] = ((char*)(&nbr))[0];
		nbr = nbr >> 8;
		i--;
	}
	*val = revnbr;
}

void	ft_victory(t_vm *vm, t_proc *current)
{
	vm->option_visu == 1 ? ft_victory_visu(vm, current) : 0;
	//ft_printf("Contestant %d, \"%s\", has won !\n",
	//	current->n_champ, current->head.prog_name, vm->cycle);
	free_chaine(vm->beg);
	exit(0);
}

void	ft_introduce(t_proc *proc)
{
	if (proc->next)
		ft_introduce(proc->next);
	ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
		proc->n_champ, proc->head.prog_size,
		proc->head.prog_name, proc->head.comment);
}

void	free_chaine(t_proc *proc)
{
	if (proc->next)
		free_chaine(proc->next);
	free(proc);
}

void	ft_print_dump(t_vm vm)
{
	int		i;

	if (vm.option_visu == 0 && vm.option_visu_d == 0)
	{
		ft_printf("0x0000 : ");
		i = -1;
		while (++i < MEM_SIZE)
		{
			if (i != 0 && i % 64 == 0)
				ft_printf("\n%#.4x : ", i);
			ft_printf("%.2hhx ", vm.arena[i][0]);
		}
		ft_printf("\n");
		exit(0);
	}
}
