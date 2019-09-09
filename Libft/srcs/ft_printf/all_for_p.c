/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:58:43 by judumay           #+#    #+#             */
/*   Updated: 2019/06/17 11:27:15 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

void			del_t_printf(t_printf *p)
{
	ft_memdel((void**)&p->flags);
	ft_memdel((void**)&p);
}

void			reset_t_printf(t_printf *p)
{
	p->flags->hash = 0;
	p->flags->zero = 0;
	p->flags->less = 0;
	p->flags->space = 0;
	p->flags->plus = 0;
	p->precision = -1;
	p->champ = -1;
	p->modifier = ft_printf_no_modifiers;
	p->conv = no_input;
	p->tmpchar = 0;
	ft_strdel(&p->conv_ret);
}

static void		init_t_printf_tab_ptr(t_printf *p)
{
	p->tab_ptr[0] = &ft_printf_s;
	p->tab_ptr[1] = &ft_printf_p;
	p->tab_ptr[2] = &ft_printf_d;
	p->tab_ptr[3] = &ft_printf_o;
	p->tab_ptr[4] = &ft_printf_u;
	p->tab_ptr[5] = &ft_printf_x;
	p->tab_ptr[6] = &ft_printf_c;
	p->tab_ptr[7] = &ft_printf_f;
	p->tab_ptr[8] = &ft_printf_percent;
	p->tab_ptr[9] = &ft_printf_no_conv;
}

t_printf		*init_t_printf(t_printf *p)
{
	if (!(p = ft_memalloc(sizeof(t_printf)))
		|| !(p->flags = ft_memalloc(sizeof(t_printf_flags)))
		|| !(p->conv_ret = ft_strnew(0)))
		exit(-1);
	init_t_printf_tab_ptr(p);
	reset_t_printf(p);
	p->error = 0;
	p->index = 0;
	p->ret = 0;
	return (p);
}
