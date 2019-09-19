/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:37:56 by mabouce           #+#    #+#             */
/*   Updated: 2019/06/05 10:38:17 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_free(t_btree **root)
{
	if (!root || !*root)
		return ;
	if ((*root)->left)
		btree_free(&((*root)->left));
	if ((*root)->right)
		btree_free(&((*root)->right));
	free(*root);
	return ;
}
