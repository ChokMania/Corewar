/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_int_cmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:01:21 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/12 11:00:12 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_int_cmp(void *c1, void *c2)
{
	long long a;
	long long b;

	a = (long long)c1;
	b = (long long)c2;
	return (a - b);
}
