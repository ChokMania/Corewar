/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:17:11 by anmauffr          #+#    #+#             */
/*   Updated: 2019/09/09 12:41:58 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../Libft/includes/libft.h"
# include "op.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** COLOR
*/

# define DEF				"\033[0m"

# define BOLD				"\033[1m"

# define RED				"\033[31m"
# define GRE				"\033[32m"
# define YEL				"\033[33m"
# define BLU				"\033[34m"
# define MAG				"\033[35m"
# define CYA				"\033[36m"

# define BACK_RED			"\033[41m"
# define BACK_GRE			"\033[42m"
# define BACK_YEL			"\033[43m"
# define BACK_BLU			"\033[44m"
# define BACK_MAG			"\033[45m"
# define BACK_CYA			"\033[46m"

/*
** ERROR
*/

# define EXIT_DUMP			20
# define ERROR_LD			1
# define ERROR_ST			2
# define ERROR_AND			3
# define ERROR_XOR			4
# define ERROR_LLD			5
# define ERROR_LDI			6
# define ERROR_STI			7
# define ERROR_ARG			8
# define ERROR_LLDI			9
# define ERROR_OPEN			10
# define ERROR_READ			11
# define ERROR_CLOSE		12
# define ERROR_MAGIC		13
# define ERROR_LABEL		14
# define ERROR_MALLOC		21
# define ERROR_OPTION		15
# define ERROR_NB_LIVE		16
# define ERROR_NAME_LEN		17
# define ERROR_COMM_LEN		18
# define ERROR_PROG_SIZE	19

/*
** TMP op_tab
**
** t_op	op_tab[17] =
** {
** 	{"name",	nb_arg	{ARG1},							{ARG2},						{ARG3},					nb,	wait,	"comment",							ocp,	dir_2	},
** 
** 	{"live",	1,		{{T_DIR,	0,		0},			{0,		0,		0},			{0,		0,		0}},	1,	10,		"alive",							0,		0		},
** 	{"ld",		2,		{{T_DIR,	T_IND,	0},			{T_REG,	0,		0},			{0,		0,		0}},	2,	5,		"load",								1,		0		},
** 	{"st",		2,		{{T_REG,	0,		0},			{T_IND,	T_REG,	0},			{0,		0,		0}},	3,	5,		"store",							1,		0		},
** 	{"add",		3,		{{T_REG,	0,		0},			{T_REG,	0,		0},			{T_REG,	0,		0}},	4,	10,		"addition",							1,		0		},
** 	{"sub",		3,		{{T_REG,	0,		0},			{T_REG,	0,		0},			{T_REG,	0,		0}},	5,	10,		"soustraction",						1,		0		},
** 	{"and",		3,		{{T_REG,	T_DIR,	T_IND},		{T_REG,	T_IND,	T_DIR},		{T_REG,	0,		0}},	6,	6,		"et (and r1, r2, r3  r1&r2 -> r3",	1,		0		},
** 	{"or",		3,		{{T_REG,	T_IND,	T_DIR},		{T_REG,	T_IND,	T_DIR},		{T_REG,	0,		0}},	7,	6,		"ou (or r1, r2, r3  r1 | r2 -> r3",	1,		0		},
** 	{"xor",		3,		{{T_REG,	T_IND,	T_DIR},		{T_REG,	T_IND,	T_DIR},		{T_REG,	0,		0}},	8,	6,		"ou (xor r1, r2, r3  r1^r2 -> r3",	1,		0		},
** 	{"zjmp",	1,		{{T_DIR,	0,		0},			{0,		0,		0},			{0,		0,		0}},	9,	20,		"jump if zero",						0,		1		},
** 	{"ldi",		3,		{{T_REG,	T_IND,	T_DIR},		{T_DIR,	T_REG,	0},			{T_REG,	0,		0}},	10,	25,		"load index",						1,		1		},
** 	{"sti",		3,		{{T_REG,	0,		0},			{T_REG,	T_DIR,	T_IND},		{T_DIR,	T_REG,	0}},	11,	25,		"store index",						1,		1		},
** 	{"fork",	1,		{{T_DIR,	0,		0},			{0,		0,		0}, 		{0,		0, 		0}},	12,	800,	"fork",								0,		1		},
** 	{"lld",		2,		{{T_DIR,	T_IND,	0},			{T_REG, 0,		0},			{0,		0, 		0}},	13,	10,		"long load",						1,		0		},
** 	{"lldi",	3,		{{T_REG,	T_DIR,	T_IND},		{T_DIR, T_REG,	0},			{T_REG,	0, 		0}},	14,	50,		"long load index",					1,		1		},
** 	{"lfork",	1,		{{T_DIR,	0,		0},			{0,		0,		0},			{0,		0, 		0}},	15,	1000,	"long fork",						0,		1		},
** 	{"aff",		1,		{{T_REG,	0,		0},			{0,		0,		0},			{0,		0, 		0}},	16,	2,		"aff",								1,		0		}
** };
**
** STRUCTURE FOR INSTRUCTION
**
** typedef struct	s_op
** {
** 	int				hexa;
** 	int				cycle;
** 	int				carry;
** 	int				nb_arg;
** 	int				arg[3][3];
** 	int				octet_param;
** 	char			*comm;
** 	char			*opcode;
** }				t_op;
*/

/*
** STRUCTURE FOR CHAMPION
*/

typedef struct	s_proc
{
	int				pc; // ou il se trouve
	int				wait; // le temps d'attente
	int				alive; // combien de vie le proc a decalrer
	int				carry;
	t_header		head; 
	unsigned int	n_champ; // numero de cchampion asssocier au proc
	unsigned int	r[REG_NUMBER]; // tous les registres
	unsigned int	during_fork; // ppour les forks
	struct s_proc	*next;
}				t_proc;

/*
** STRUCTURE FOR MAP
*/

typedef struct	s_vm
{
	int				nb_champ; 
	int				fd[MAX_PLAYERS];
	long			option_dump;
	long			option_verbose;
	t_proc			*proc;
	t_proc			*beg;
	unsigned int	cycle;
	unsigned int	cycle_to_die;
	unsigned int	total_to_die;
	unsigned int	nb_check_cycle;
	unsigned int	nb_live_champ[MAX_PLAYERS];
	unsigned char	arena[MEM_SIZE][2];
}				t_vm;

/*
** FONCTION
*/

void			ft_error(int err, int nb_line);
void			ft_print_vm(t_vm vm);
void			ft_print_dump(t_vm vm);
void			ft_put_instruct(int pc, unsigned int arg_value[3], unsigned int arg_size[3]);
void			ft_invert_byte(unsigned int *val);
void			ft_init_vm(t_vm *vm);
void			ft_cycle_to_die(t_vm *vm);
void			ft_dead_proc(t_vm *vm);
void			ft_choise_opcode(t_vm *vm, int *pc, unsigned char opcode);
void			ft_wait(t_vm *vm, unsigned char opcode);

void			ft_parsing(t_vm *vm, char **av);
void			ft_introduce(t_vm *vm);
void			ft_args(int ac, char **av, t_vm *vm, char *tab[5]);

void			op_live(t_vm *vm, int *pc);
void			op_ld(t_vm *vm, int *pc);
void			op_st(t_vm *vm, int *pc);
void			op_add(t_vm *vm, int *pc);
void			op_sub(t_vm *vm, int *pc);
void			op_and(t_vm *vm, int *pc);
void			op_or(t_vm *vm, int *pc);
void			op_xor(t_vm *vm, int *pc);
void			op_zjmp(t_vm *vm, int *pc);
void			op_ldi(t_vm *vm, int *pc);
void			op_sti(t_vm *vm, int *pc);
void			op_fork(t_vm *vm, int *pc);
void			op_lld(t_vm *vm, int *pc);
void			op_lldi(t_vm *vm, int *pc);
void			op_lfork(t_vm *vm, int *pc);
void			op_aff(t_vm *vm, int *pc);

#endif