/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:13 by anmauffr          #+#    #+#             */
/*   Updated: 2019/10/04 01:13:46 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	idx_mod_16(unsigned int realpc, unsigned int jump)
{
	return (jump > 32768 ? (realpc - (-jump % IDX_MOD)) % MEM_SIZE
		: (realpc + jump % IDX_MOD) % MEM_SIZE);
}

/*
** TMP FONCTION
**
** Voir si on a besoin de idx_mod en uint_32 ou si on a que besoin de uint_16
*/

// unsigned int	idx_mod_32(unsigned int realpc, unsigned int jump)
// {
// 	return (jump > 2147483648 ? (realpc - (-jump % IDX_MOD)) % MEM_SIZE
// 		: (realpc + jump % IDX_MOD) % MEM_SIZE);
// }
