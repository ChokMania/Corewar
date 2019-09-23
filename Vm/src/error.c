/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:34:57 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/23 13:50:42 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_fill_tab_err(char *tab_err[20])
{
	tab_err[0] = "0";
	tab_err[1] = "ld";
	tab_err[2] = "st";
	tab_err[3] = "and";
	tab_err[4] = "xor";
	tab_err[5] = "lld";
	tab_err[6] = "ldi";
	tab_err[7] = "sti";
	tab_err[8] = "arg";
	tab_err[9] = "lldi";
	tab_err[10] = "open";
	tab_err[11] = "read";
	tab_err[12] = "close";
	tab_err[13] = "magic";
	tab_err[14] = "label";
	tab_err[15] = "Bad utilisation -> Options";
	tab_err[16] = "nb live";
	tab_err[17] = "name len";
	tab_err[18] = "comm len";
	tab_err[19] = "Size of the program";
	tab_err[20] = "end dump option";
	tab_err[21] = "malloc";
}

void	ft_error(int err, int nb_line, t_vm *vm)
{
	char	*tab_err[20];

	if (vm->option_visu == 1)
		endwin();
	if (vm->beg != NULL)
		free_chaine(vm->beg);
	ft_fill_tab_err(tab_err);
	if (nb_line == -1)
		ft_dprintf(2, "error : %d || %s\n", err, tab_err[err]);
	else if (err == ERROR_NB_LIVE)
		ft_dprintf(2, "Player %d didn't show enough lives\n", nb_line);
	else if (err == ERROR_PROG_SIZE)
		ft_dprintf(2, "error : %d || %s\n",
		err, tab_err[err]);
	else
		ft_dprintf(2, "error : %d || %s, line %d\n",
		err, tab_err[err], nb_line);
	exit(0);
}
