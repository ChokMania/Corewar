/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:34:57 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 16:25:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_fill_tab_err(char *tab_err[20])
{
	tab_err[0] = ft_strdup("0");
	tab_err[1] = ft_strdup("ld");
	tab_err[2] = ft_strdup("st");
	tab_err[3] = ft_strdup("and");
	tab_err[4] = ft_strdup("xor");
	tab_err[5] = ft_strdup("lld");
	tab_err[6] = ft_strdup("ldi");
	tab_err[7] = ft_strdup("sti");
	tab_err[8] = ft_strdup("arg");
	tab_err[9] = ft_strdup("lldi");
	tab_err[10] = ft_strdup("open");
	tab_err[11] = ft_strdup("read");
	tab_err[12] = ft_strdup("close");
	tab_err[13] = ft_strdup("magic");
	tab_err[14] = ft_strdup("label");
	tab_err[15] = ft_strdup("Bad utilisation -> Options");
	tab_err[16] = ft_strdup("nb live");
	tab_err[17] = ft_strdup("name len");
	tab_err[18] = ft_strdup("comm len");
	tab_err[19] = ft_strdup("Size of the program");
	tab_err[20] = ft_strdup("end dump option"); // finir de l'ajouter
	tab_err[21] = ft_strdup("malloc"); // finir de l'ajouter
}

void	ft_error(int err, int nb_line)
{
	char	*tab_err[20];

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
	endwin();
	exit(0);
}
