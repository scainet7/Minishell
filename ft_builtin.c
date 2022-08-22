/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:29 by snino             #+#    #+#             */
/*   Updated: 2022/08/22 19:04:29 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin(t_mini *mini, t_cmd *cmd, int *pipe_fd)
{
	if (cmd->fd[STDIN_FILENO] != STDIN_FILENO)
		close(cmd->fd[STDIN_FILENO]);
	if (cmd->next)
	{
		if (cmd->fd[STDOUT_FILENO] == STDOUT_FILENO)
			cmd->fd[STDOUT_FILENO] = pipe_fd[P_IN];
		cmd->next->fd[STDIN_FILENO] = pipe_fd[P_OUT];
	}
	if (cmd && !ft_memcmp(cmd->comand[0], "pwd", 4))
		ft_pwd(cmd);
	else if (cmd && !ft_memcmp(cmd->comand[0], "env", 4))
		ft_env(mini, cmd);
	else if (cmd && !ft_memcmp(cmd->comand[0], "echo", 5))
		ft_echo(mini, cmd);
	else if (cmd && !ft_memcmp(cmd->comand[0], "unset", 6))
		ft_unset(mini, cmd);
	else if (cmd && !ft_memcmp(cmd->comand[0], "cd", 3))
		ft_cd(mini, cmd);
	else if (cmd && !ft_memcmp(cmd->comand[0], "export", 7))
		ft_export(mini, cmd);
	else if (cmd && !ft_memcmp(cmd->comand[0], "exit", 5))
		ft_exit(mini, cmd);
}
