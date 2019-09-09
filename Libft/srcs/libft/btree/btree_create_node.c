/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 08:44:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 15:28:53 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*btree_create_node(void *content)
{
	t_btree	*new;

	if (!(new = malloc(sizeof(t_btree))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->left = NULL;
		new->right = NULL;
	}
	else
	{
		new->content = content;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
