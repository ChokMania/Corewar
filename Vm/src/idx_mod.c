/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:13 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/02 14:35:50 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	idx_mod(unsigned int realpc, unsigned int index)
{
	if ((index < realpc && realpc - index <= IDX_MOD) || (index > realpc && index - realpc <= IDX_MOD) || (index > realpc && realpc + MEM_SIZE - index <= IDX_MOD) || (index < realpc && index + MEM_SIZE - realpc <= IDX_MOD))
		;
	else if (index < realpc)
		index = realpc - (realpc - index) % IDX_MOD;
	else if (index > realpc)
		index = (realpc + (index % IDX_MOD) - 1) % MEM_SIZE;
	return (index);
}