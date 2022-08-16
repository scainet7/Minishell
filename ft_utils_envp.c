/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:52:08 by snino             #+#    #+#             */
/*   Updated: 2022/08/16 15:52:08 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_variable(t_list *var, char *line)
{
	t_list	*buf;

	buf = var;
	while (buf)
	{
		if (!ft_memcmp(buf->content, line, ft_strlen(line) + 1) \
		|| ft_memcmp(buf->content, line, ft_strlen(line) + 1) == '=')
			return (buf);
		buf = buf->next;
	}
	return (NULL);
}
