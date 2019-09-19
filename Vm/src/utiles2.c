/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:56:33 by judumay           #+#    #+#             */
/*   Updated: 2019/09/19 14:46:07 by judumay          ###   ########.fr       */
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
	vm->option_visu == 1 ? ft_victory_visu(vm, current): 0;
	ft_printf("Contestant %d, \"%s\", has won ! at cycle %d\n",
		current->n_champ, current->head.prog_name, vm->cycle);
	free_chaine(vm->beg);
	exit(0);
}

void	ft_introduce(t_vm *vm)
{
	int		i;

	vm->beg = vm->proc;
	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->nb_champ)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			i + 1, vm->proc->head.prog_size, vm->proc->head.prog_name,
			vm->proc->head.comment);
		vm->proc = vm->proc->next;
	}
	vm->proc = vm->beg;
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
