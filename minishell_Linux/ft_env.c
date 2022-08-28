/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:46:45 by snino             #+#    #+#             */
/*   Updated: 2022/08/28 15:46:44 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_mini *mini, t_cmd *cmd)
{
	t_list	*tmp_list;
	char	*tmp;

	tmp_list = mini->envp_list;
	tmp = NULL;
	while (tmp_list)
	{
		tmp = tmp_list->content;
		if (tmp_list->flag == 0)
		{
			ft_putstr_fd(tmp, cmd->fd[1]);
			ft_putstr_fd("\n", cmd->fd[1]);
		}
		tmp_list = tmp_list->next;
	}
}
