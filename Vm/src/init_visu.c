/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:25:35 by judumay           #+#    #+#             */
/*   Updated: 2019/09/09 15:53:54 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	init_color_vm(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_RED);
	init_pair(7, COLOR_WHITE, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_BLACK);
}

char	*get_hexa(int nb)
{
	char	*str;
	char	*base;

	if (nb < 0 || nb > 255)
		return (0);
	if (!(str = (char*)malloc(sizeof(char) * 3)))
		return (0);
	base = "0123456789abcdef";
	str[0] = base[nb / 16];
	str[1] = base[nb % 16];
	str[2] = 0;
	base = 0;
	return (str);
}

void	print_arena(t_vm *vm, int i)
{
	int color;

	color = 9;
	vm->visu->str = get_hexa(vm->arena[i / 3][0]);
	mvwprintw(vm->visu->arena, 1 + (i / 192), 2 + (i % 192), vm->visu->str);
	if (vm->arena[i / 3][1] != 0)
		color = vm->arena[i / 3][1];
	mvwchgat(vm->visu->arena, 1 + (i / 192), 2 + (i % 192), 2, A_BOLD, color, 0);
	mvwprintw(vm->visu->arena, 1 + (i / 192), 4 + (i % 192), " ");
}

void	init_champ_in_visu(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE * 3)
	{
		print_arena(vm, i);
		i += 3;
	}
}

void	create_player_hud(t_vm *vm, int *i)
{
	while ((*i) < vm->nb_champ)
	{
		vm->visu->str = ft_itoa((*i) + 1);
		mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 5, "Player   :");
		mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 12, vm->visu->str);
		wattron(vm->visu->hud, COLOR_PAIR((*i) + 1));
		if (ft_strlen(vm->proc->head.prog_name) >= 120)
			mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 18, ft_strsub(vm->proc->head.prog_name, 0, 92));
		else
			mvwprintw(vm->visu->hud, 18 + ((*i) * 4), 18, vm->proc->head.prog_name);
		wattroff(vm->visu->hud, COLOR_PAIR(((*i) + 1)));
		mvwprintw(vm->visu->hud, 19 + ((*i) * 4), 7, "Last live :\t\t\t0");
		mvwprintw(vm->visu->hud, 20 + ((*i) * 4), 7
		, "live in current period :\t\t0");
		ft_strdel(&(vm->visu->str));
		(*i)++;
		vm->proc = vm->proc->next;
	}
	vm->proc = vm->beg;
	mvwprintw(vm->visu->hud, 19 + ((*i) * 4), 35
			, "Live breakdown for current period :");
	mvwprintw(vm->visu->hud, 22 + ((*i) * 4), 37
			, "Live breakdown for last period :");
	wattroff(vm->visu->hud, A_BOLD);
}

void	write_infos_hud(t_vm *vm, int i)
{
	vm->visu->str = ft_itoa(CYCLE_TO_DIE);
	mvwprintw(vm->visu->hud, 26 + (i * 4), 5, "CYCLE TO DIE :");
	mvwprintw(vm->visu->hud, 26 + (i * 4), 20, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	vm->visu->str = ft_itoa(CYCLE_DELTA);
	mvwprintw(vm->visu->hud, 28 + (i * 4), 5, "CYCLE_DELTA :");
	mvwprintw(vm->visu->hud, 28 + (i * 4), 20, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	vm->visu->str = ft_itoa(NBR_LIVE);
	mvwprintw(vm->visu->hud, 30 + (i * 4), 5, "NBR_LIVE :");
	mvwprintw(vm->visu->hud, 30 + (i * 4), 20, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	vm->visu->str = ft_itoa(MAX_CHECKS);
	mvwprintw(vm->visu->hud, 32 + (i * 4), 5, "NBR_CHECKS :");
	mvwprintw(vm->visu->hud, 32 + (i * 4), 20, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	wrefresh(vm->visu->hud);
}

void	init_visual_hud(t_vm *vm)
{
	int		i;

	i = 0;
	wattron(vm->visu->hud, A_BOLD);
	mvwprintw(vm->visu->hud, 5, 45, "**   PAUSE   **");
	mvwprintw(vm->visu->hud, 11, 5, "Cycle/second limit : 50");
	mvwprintw(vm->visu->hud, 13, 5, "Cycle : 0");
	mvwprintw(vm->visu->hud, 15, 5, "Processes :");
	vm->visu->str = ft_itoa(vm->nb_champ);
	mvwprintw(vm->visu->hud, 15, 17, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	create_player_hud(vm, &i);
	mvwprintw(vm->visu->hud, 20 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(vm->visu->hud, 20 + (i * 4), 56
	, "--------------------------------------------------]");
	mvwprintw(vm->visu->hud, 23 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(vm->visu->hud, 23 + (i * 4), 56
	, "--------------------------------------------------]");
	wattron(vm->visu->hud, A_BOLD);
	write_infos_hud(vm, i);
	wrefresh(vm->visu->hud);

}

void	ft_init_visu(t_vm *vm)
{
	if (!(vm->visu = (t_visu*)malloc(sizeof(t_visu) * 1)))
		return ;
	bzero(vm->visu, sizeof(t_visu));
	initscr();
	noecho();
	timeout(1);
	curs_set(0);
	init_color_vm();
	vm->visu->hud = newwin(66, 111, 0, 195);
	vm->visu->arena = newwin(66, 195, 0, 0);
	vm->visu->cps = 50;
	refresh();
	box(vm->visu->arena, 0, 0);
	box(vm->visu->hud, 0, 0);
	init_champ_in_visu(vm);
	wrefresh(vm->visu->arena);
	init_visual_hud(vm);
	sleep(1000000);
	endwin();
	exit(0);
}
