/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:02:56 by judumay           #+#    #+#             */
/*   Updated: 2019/06/25 12:06:17 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

void	test_binarytree(int ac, char **av, int *i)
{
	t_btree	*tree;

	miniprintf("%%%%Btree%%%%%%\n\n", "BOLD", "UNDER", "END", "BLUE", "NOEND");
	tree = NULL;
	btree_insert_data(&tree, (void *)5, &btree_int_cmp);
	btree_insert_data(&tree, (void *)5, &btree_int_cmp);
	btree_insert_data(&tree, (void *)0, &btree_int_cmp);
	btree_insert_data(&tree, (void *)-10, &btree_int_cmp);
	btree_print(tree);
	btree_free(&tree);
	miniprintf("");
}

void	test_miniprintf(int ac, char **av, int *i)
{
	char		*test;
	long long	lo;
	long long	nlo;

	miniprintf("%%%%mnpf%%%%%%\n\n", "BOLD", "UNDER", "END", "GREEN", "NOEND");
	lo = 9223372036854775800;
	nlo = -9223372036854775800;
	miniprintf("%%Test color blue miniprintf\n%%", "BLUE", "END");
	test = NULL;
	miniprintf("%s%s\n", "test empty string :", test);
	miniprintf("%%s:%s\ti: %i\td: %d\tc:%c%%\n", "GREEN", "test", -1245, "END");
	miniprintf("\n\n\ntesting long long miniprintf\n\n\n");
	miniprintf("%%+ll: %lld\t-ll : %lli\t\n\n", "RED", lo, nlo);
	miniprintf("\n\n\nis it in red color?%% %%\n\n", "RED", "NOEND");
	miniprintf("and now ? red color?\n", "RED", "NOEND");
	miniprintf("");
}

void	test_str(int ac, char **av, int *i)
{
	char	*str;

	miniprintf("%%%%str%%%%%%\n\n", "BOLD", "UNDER", "END", "YELLOW", "NOEND");
	str = ft_strdup("test\n");
	ft_putstr(str);
	free(str);
	str = ft_strdupd(ft_strremove_char("remov ' ' of  \t string", " s\n\t"));
	ft_putstr(str);
	ft_putchar('\n');
	free(str);
	str = ft_strdupd(ft_strremove_char("j", "j"));
	ft_putstr("test strremove quand on remove tout");
	ft_putstr(str);
	ft_putchar('\n');
	free(str);
	str = ft_strdupd(ft_strremove_char("strremove_char , remov 'H'min\n", "h"));
	free(str);
	miniprintf("");
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	printf("\nstart testing\n");
	test_miniprintf(ac, av, &i);
	test_binarytree(ac, av, &i);
	test_str(ac, av, &i);
	return (0);
}
