/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:52:08 by snino             #+#    #+#             */
/*   Updated: 2022/08/18 18:24:51 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_errno(t_mini *mini)
{
	t_list	*tmp_list;

	tmp_list = ft_search_envp(mini->envp_list, "?");
	free(tmp_list->content);
	tmp_list->content = ft_strjoin_free("?=", ft_itoa(mini->error), 3);
	tmp_list->flag = -1;
}

t_list	*ft_search_envp(t_list *envp, char *line)
{
	t_list	*buff;

	buff = envp;
	while (buff)
	{
		if (!ft_memcmp(buff->content, line, ft_strlen(line) + 1) \
		|| ft_memcmp(buff->content, line, ft_strlen(line) + 1) == '=')
			return (buff);
		buff = buff->next;
	}
	return (NULL);
}
