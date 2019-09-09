/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:18:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/18 18:36:48 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		btree_display(t_btree *root, int lvlcnt)
{
	long long	i;
	int			lvl;

	i = (long long)(root->content);
	lvl = lvlcnt;
	if (root->left)
		btree_display(root->left, lvl - 1);
	while (lvlcnt-- > 0)
		ft_putstr("     ");
	ft_putnbr(i);
	ft_putstr("----|");
	ft_putchar('\n');
	if (root->right)
		btree_display(root->right, lvl - 1);
}

void			btree_print(t_btree *root)
{
	int lvlcnt;

	lvlcnt = btree_lvl_count(root);
	btree_display(root, lvlcnt);
}
