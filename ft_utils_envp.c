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

void	change_errno(t_mini *mini)
{
	t_list	*temp;

	temp = find_variable(mini->envp_list, "?");
	free(temp->content);
	temp->content = ft_strjoin_free("?=", ft_itoa(mini->error), 3);
	temp->flag = -1;
}

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
