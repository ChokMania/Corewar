/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:29:17 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 10:24:00 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					ft_introduce(t_vm *vm)
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

static void				ft_check_header(t_header head, unsigned char proc)
{
	int		len_nam;
	int		len_com;

	len_nam = ft_strlen(head.prog_name);
	len_com = ft_strlen(head.comment);
	if (head.magic != COREWAR_EXEC_MAGIC)
		ft_error(ERROR_MAGIC, proc);
	else if (!len_nam || len_nam > PROG_NAME_LENGTH)
		ft_error(ERROR_NAME_LEN, proc);
	else if (!head.prog_size || head.prog_size > CHAMP_MAX_SIZE)
		ft_error(ERROR_PROG_SIZE, proc);
	else if (!len_com || len_com > COMMENT_LENGTH)
		ft_error(ERROR_COMM_LEN, proc);
}

static unsigned char	ft_read(int fd, int proc)
{
	int		ret;
	char	buf;

	if ((ret = read(fd, &buf, sizeof(char))) == -1)
		ft_error(ERROR_READ, proc);
	return (buf);
}

static void				ft_pars_header(int *fd, t_header *head, char *av)
{
	(*fd = open(av, O_RDONLY)) == -1 ? ft_error(ERROR_OPEN, -1) : 0;
	read(*fd, head, sizeof(t_header)) == -1 ? ft_error(ERROR_READ, -1) : 0;
	ft_invert_byte(&head->magic);
	ft_invert_byte(&head->prog_size);
}

/*
** CREATION DE L'ARENE EN PLASSANT LES CHANPIONS EN MEME TEMPS
** CETTE FONCTION SERT AUSSI A DONNER LE NUMERO DU CHAMPION AU CHAMPION
** SONT PC DE DEPART EN GROS
*/

void					ft_parsing(t_vm *vm, char **av)
{
	int				index;
	int				nb_player;
	unsigned int	j;

	index = -1;
	vm->beg = vm->proc;
	while (++index < vm->nb_champ)
	{
		ft_pars_header(&vm->fd[index], &vm->proc->head, av[index]);
		ft_check_header(vm->proc->head, index + 1);
		vm->proc->pc = index * (MEM_SIZE / vm->nb_champ);
		vm->proc->n_champ = index + 1;
		vm->proc = vm->proc->next;
	}
	vm->proc = vm->beg;
	index = 0;
	nb_player = -1;
	while (++nb_player < vm->nb_champ)
	{
		j = 0;
		while (j++ < vm->proc->head.prog_size
			&& (vm->arena[index][1] = nb_player + 1))
			vm->arena[index++][0] = ft_read(vm->fd[nb_player], nb_player + 1);
		while (index < (nb_player + 1) * MEM_SIZE / vm->nb_champ
			&& !(vm->arena[index][1] = 0))
			vm->arena[index++][0] = 0;
		vm->proc = vm->proc->next;
	}
	vm->proc = vm->beg;
	nb_player = -1;
	while (++nb_player < vm->nb_champ)
		close(vm->fd[nb_player]) == -1 ? ft_error(ERROR_CLOSE, nb_player + 1)
			: 0 ;
}
