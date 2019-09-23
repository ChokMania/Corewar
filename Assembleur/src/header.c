/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <mabouce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 07:16:25 by judumay           #+#    #+#             */
/*   Updated: 2019/06/26 14:32:58 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_check_header_not_open(t_struct *s, t_header *header
				, int len, int len_name)
{
	int		len_comment;

	len_comment = ft_strlen(COMMENT_CMD_STRING);
	if (!s->line)
		return ;
	if (!ft_strncmp(s->line, NAME_CMD_STRING, len_name))
	{
		s->name = s->nb_line;
		s->index = 0;
		if ((len = ft_strlen(s->line) - len_name - 3) > PROG_NAME_LENGTH)
			ft_error(ERROR_LEN_NAME, s, NULL);
		ft_get_first_line_name(s, header);
	}
	else if (!ft_strncmp(s->line, COMMENT_CMD_STRING, len_comment))
	{
		s->comment = s->nb_line;
		s->index = 0;
		if ((len = ft_strlen(s->line) - len_comment - 3) > COMMENT_LENGTH)
			ft_error(ERROR_LEN_COMM, s, NULL);
		ft_get_first_line_comm(s, header);
	}
	else
		ft_error(ERROR_HEADER, s, NULL);
}

int				ft_find_occu(char *str)
{
	int i;
	int ret;

	i = ft_strlen(str);
	while (str[i] != '\"')
		i--;
	while (str[++i] && (str[i] == ' ' || str[i] == '\t'))
		;
	ret = !str[i] || str[i] == '#' ? 1 : 0;
	return (ret);
}

void			ft_check_header(t_struct *s, t_header *header)
{
	int		len_name;

	len_name = ft_strlen(NAME_CMD_STRING);
	if (s->namefirstopen == 1)
		ft_get_others_line_name(s, header);
	else if (s->commentfirstopen == 1)
		ft_get_others_line_comment(s, header);
	else if (s->namefirstopen == 0 || s->commentfirstopen == 0)
		ft_check_header_not_open(s, header, 0, len_name);
}
