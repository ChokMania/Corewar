/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:34:47 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 15:08:53 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

static void		ft_fill_tab_with_unplaced_champs(char *tab[5],
					char *ordre[5], t_vm *vm)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ordre[i] != NULL)
	{
		while (j < 4 && tab[j] != NULL)
			j++;
		j == 4 ? ft_error(ERROR_OPTION, -1) : 0;
		tab[j] = ordre[i];
		vm->nb_champ++;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (tab[i] == NULL && tab[i + 1] != NULL)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static int		ft_option(int ac, char **av, t_vm *vm, char *tab[5])
{
	int i;

	if (!(i = 0) && (!ft_strcmp(av[0], "-dump") || !ft_strcmp(av[0], "-d")))
	{
		if (ac < 2 || ft_strlen(av[1]) > 10
			|| (vm->option_dump = ft_atol(av[1]) + 1) < 1)
			ft_error(ERROR_OPTION, -1);
		return (1);
	}
	else if (ft_strcmp(av[0], "-verbose") == 0 || ft_strcmp(av[0], "-v") == 0)
	{
		if (ac < 2 || ft_strlen(av[1]) > 1 || ((vm->option_verbose =
			ft_atoi(av[1])) != 0 && vm->option_verbose != 1))
			ft_error(ERROR_OPTION, -1);
		return (1);
	}
	else if (ft_strcmp(av[0], "-number") == 0 || ft_strcmp(av[0], "-n") == 0)
	{
		if (ac < 3 || ft_strlen(av[1]) > 1 || (i = ft_atoi(av[1])) < 1 || i > 4)
			ft_error(ERROR_OPTION, -1);
		tab[i - 1] == NULL ? tab[i - 1] = av[2] : ft_error(ERROR_OPTION, -1);
		vm->nb_champ++;
		return (2);
	}
	/*else if (ft_strcmp(av[0], "--visual") == 0 || ft_strcmp(av[0], "-vi") == 0)
	{
		vm->option_visu = 1;
		return (1);
	}*/
	return (0);
}

void			ft_args(int ac, char **av, t_vm *vm, char *tab[5])
{
	int		i;
	int		j;
	int		temp;
	char	*ordre[5];

	i = 0;
	j = 0;
	bzero(ordre, sizeof(char*) * 5);
	vm->option_visu = 1;
	while (++i < ac)
	{
		temp = 0;
		if (av[i][0] == '-')
		{
			temp = ft_option(ac - i, av + i, vm, tab);
			if (temp == 0)
				ordre[j++] = av[i];
			i += temp;
		}
		else
			ordre[j++] = av[i];
		if (j == 5)
			ft_error(ERROR_OPTION, -1);
	}
	ft_fill_tab_with_unplaced_champs(tab, ordre, vm);
}
