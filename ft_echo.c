/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:30:08 by snino             #+#    #+#             */
/*   Updated: 2022/08/18 14:22:01 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_echo_print(t_mini *mini, char **cmd, int fd, int i)
{
	t_list	*tmp_list;

	tmp_list = mini->words_list_mod;
	while (tmp_list && tmp_list->content != cmd[i])
		tmp_list = tmp_list->next;
	while (tmp_list && cmd[i] && tmp_list->content == cmd[i])
	{
		ft_putstr_fd(cmd[i], fd);
		++i;
		tmp_list = tmp_list->next;
	}
}

void 	ft_echo(t_mini *mini, t_cmd *cmd)
{
	if (cmd->comand[1] && ft_strnstr(cmd->comand[1], "-n", 2))
		ft_echo_print(mini, cmd->comand, mini->cmd->fd[1], 2);
	else
	{
		ft_echo_print(mini, cmd->comand, mini->cmd->fd[1], 1);
		ft_putstr_fd("\n", mini->cmd->fd[1]);
	}
}