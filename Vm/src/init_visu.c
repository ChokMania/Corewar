/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:25:35 by judumay           #+#    #+#             */
/*   Updated: 2019/09/10 16:21:58 by judumay          ###   ########.fr       */
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

void	modif_cps(t_vm *vm, int to_add)
{
	vm->visu->cps += to_add;
	if (vm->visu->cps > 1000)
		vm->visu->cps = 1000;
	else if (vm->visu->cps < 10)
		vm->visu->cps = 10;
	wattron(vm->visu->hud, A_BOLD);
	vm->visu->str = ft_itoa(vm->visu->cps);
	mvwprintw(vm->visu->hud, 11, 26, vm->visu->str);
	mvwprintw(vm->visu->hud, 11, 26 + ft_strlen(vm->visu->str), "    ");
	ft_strdel(&(vm->visu->str));
	wrefresh(vm->visu->hud);
}

int	handle_pause(t_vm *vm, int *pause, int p_or_r)
{
	wattron(vm->visu->hud, A_BOLD);
	if (p_or_r == 1)
	{
		mvwprintw(vm->visu->hud, 5, 45, "**   PAUSE   **");
		(*pause) *= -1;
		wrefresh(vm->visu->hud);
	}
	else if (p_or_r == 2)
	{
		mvwprintw(vm->visu->hud, 5, 45, "**   PAUSE   **");
		(*pause) = 1;
		wrefresh(vm->visu->hud);
	}
	else
		mvwprintw(vm->visu->hud, 5, 45, "**  RUNNING  **");
	wattroff(vm->visu->hud, A_BOLD);
	return(1);
}

void	get_key(t_vm *vm)
{
	int			i;
	static int	pause = 1;

	while (1)
	{
		timeout(0);
		if ((i = getch()) == ' ')
			handle_pause(vm, &pause, 1);
		else if (i == 'p' && handle_pause(vm, &pause, 2))
			break;
		else if (i == 'r' && vm->visu->cps < 1000)
			modif_cps(vm, 10);
		else if (i == 'e' && vm->visu->cps < 1000)
			modif_cps(vm, 1);
		else if (i == 'm' && vm->visu->cps < 1000)
			modif_cps(vm, 100);
		else if (i == 'w' && vm->visu->cps > 10)
			modif_cps(vm, -1);
		else if (i == 'q' && vm->visu->cps > 10)
			modif_cps(vm, -10);
		else if (i == 'n' && vm->visu->cps > 10)
			modif_cps(vm, -100);
		if (pause == -1)
		{
			handle_pause(vm, &pause, 0);
			break ;
		}
	}
	timeout(1);
	if (!((vm->visu->cps == 10 && (i == 'w' || i == 'q'))
		|| (vm->visu->cps == 1000 && (i == 'r' || i == 'e' || i == 'm'))))
		usleep(1000000 / vm->visu->cps);

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
	get_key(vm);
}

void	refresh_pc(t_vm *vm)
{
	t_proc	*pr;

	pr = vm->proc;
	while (pr)
	{
		mvwchgat(vm->visu->arena, 1 + ((pr->pc * 3) / 192)
		, 2 + ((pr->pc * 3) % 192), 2, A_REVERSE
		, vm->arena[pr->pc][1], 0);
		pr = pr->next;

	}
	wrefresh(vm->visu->arena);
	pr = vm->proc;
	while (pr)
	{
		if (vm->arena[pr->pc][1] == 0)
			mvwchgat(vm->visu->arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_BOLD
			, 10, 0);
		else
			mvwchgat(vm->visu->arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_BOLD
			, vm->arena[pr->pc][1], 0);
		pr = pr->next;
	}
}

void	visual_sti(t_vm *vm, unsigned int arg_value[3], unsigned int	arg_size[3])
{
	int	i;
	int		pc;

	pc = 0;
	if ((i = 4) && arg_size[1] == T_REG)
		pc = vm->proc->r[arg_value[1]] % IDX_MOD - T_REG;
	else if (arg_size[1] == T_DIR)
		pc = arg_value[1] % IDX_MOD - T_DIR;
	else if (arg_size[1] == T_IND)
		pc = (arg_value[1] % IDX_MOD) - T_DIR;
	if (arg_size[2] == T_REG)
		pc += vm->proc->r[arg_value[2]] % IDX_MOD - T_REG;
	else if (arg_size[2] == T_DIR)
		pc += arg_value[2] % IDX_MOD - T_DIR;
	pc < 0 ? pc = MEM_SIZE + pc % MEM_SIZE : 0;
	pc >= MEM_SIZE ? pc %= MEM_SIZE : 0;
	pc += vm->proc->pc - 2;
	while (--i >= 0)
	{
		vm->visu->str = get_hexa(vm->arena[pc + i][0]);
		mvwprintw(vm->visu->arena, 1 + ((3 * (pc + i)) / 192) , 2 + ((3 * (pc + i)) % 192), vm->visu->str);
		mvwchgat(vm->visu->arena, 1 + ((3 * (pc + i)) / 192) , 2 + ((3 * (pc + i)) % 192), 2, A_BOLD, vm->arena[pc + i][1], 0);
		ft_strdel(&(vm->visu->str));
	}
	wrefresh(vm->visu->arena);
}

void	visual_st(t_vm *vm, unsigned int arg_value[3], unsigned int	arg_size[3])
{
	int	i;
	int pc;

	pc = vm->proc->pc - 2;
	if ((i = 4) && ((arg_size[1] == T_REG && pc + vm->proc->r[arg_value[1]] >= MEM_SIZE)
		|| (arg_size[1] == T_IND && pc + arg_value[1] >= MEM_SIZE)))
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
		vm->visu->str = get_hexa(vm->arena[pc + i][0]);
		mvwprintw(vm->visu->arena, 1 + ((3 * (pc + i)) / 192) , 2 + ((3 * (pc + i)) % 192), vm->visu->str);
		mvwchgat(vm->visu->arena, 1 + ((3 * (pc + i)) / 192) , 2 + ((3 * (pc + i)) % 192), 2, A_BOLD, vm->arena[pc + i][1], 0);
		ft_strdel(&(vm->visu->str));
	}
	wrefresh(vm->visu->arena);
}


void	visual_every_cycle(t_vm *vm)
{
	//int	i;

	wattron(vm->visu->hud, A_BOLD);
	vm->visu->str = ft_itoa(vm->cycle);
	mvwprintw(vm->visu->hud, 13, 13, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	wattroff(vm->visu->hud, A_BOLD);
	wrefresh(vm->visu->hud);
	// if ((vm->cycle % 100) == 0)
	// {
	// 	i = 0;
	// 	while (i < MEM_SIZE)
	// 	{
	// 		if (vm->visu->color_arena[i] != 9)
	// 			mvwchgat(vm->visu->arena, 1 + ((3 * i) / 192)
	// 			, 2 + ((3 * i) % 192), 2, A_NORMAL, vm->visu->color_arena[i]
	// 			, 0);
	// 		i++;
	// 	}
	// }
	get_key(vm);
}

int ft_list_count_vm(t_proc *begin_list)
{
	int i;
	t_proc *current;

	i = 0;
	current = begin_list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	refresh_process(t_vm *vm)
{
	wattron(vm->visu->hud, A_BOLD);
	mvwprintw(vm->visu->hud, 15, 17, "      ");
	vm->visu->str = ft_itoa(ft_list_count_vm(vm->proc));
	mvwprintw(vm->visu->hud, 15, 17, vm->visu->str);
	wattroff(vm->visu->hud, A_BOLD);
	wrefresh(vm->visu->hud);
	ft_strdel(&(vm->visu->str));
}

void	refresh_live_by_champ(t_vm *vm, int i)
{
	wattron(vm->visu->hud, A_BOLD);
	vm->visu->str = ft_itoa(vm->proc->last_live);
	mvwprintw(vm->visu->hud, 19 + (i * 4), 40, vm->visu->str);
	ft_strdel(&(vm->visu->str));	
	vm->visu->str = ft_itoa(vm->nb_live_champ[i]);
	mvwprintw(vm->visu->hud, 20 + (i * 4), 40, vm->visu->str);
	ft_strdel(&(vm->visu->str));
	wattroff(vm->visu->hud, A_BOLD);
}

void	refresh_live(t_vm *vm)
{
	int		i;
	int		j;
	int		tmp;
	int		total_live;

	i = 0;
	j = 0;
	total_live = 0;
	while (i < vm->nb_champ)
	{
		refresh_live_by_champ(vm, i);
		total_live += vm->nb_live_champ[i];
		i++;
	}
	i = -1;
	tmp = 0;
	// checker si on atteind pas 0 pour certains et checker quon qrrive bien a 100 traits
	if (total_live != 0)
		while (j < 100)
		{
			if (tmp == 0)
				tmp = (vm->nb_live_champ[++i] * 100 / total_live);
			else
			{
				wattron(vm->visu->hud, COLOR_PAIR(i + 1));
				mvwprintw(vm->visu->hud, 20 + (vm->nb_champ * 4), 6 + j++, "-");
				tmp--;
				wattroff(vm->visu->hud, COLOR_PAIR(i + 1));
			}
		}
	
}