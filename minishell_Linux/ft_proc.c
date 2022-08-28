/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:35:10 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 17:42:39 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_child_proc(t_mini *mini, t_cmd *tmp_cmd, int *i, int *pipe_fd)
{
	char	**tmp_envp;

	if (tmp_cmd->next)
		tmp_cmd->next->fd[STDIN_FILENO] = pipe_fd[P_OUT];
	if (tmp_cmd->next && tmp_cmd->fd[STDOUT_FILENO] == STDOUT_FILENO)
		tmp_cmd->fd[STDOUT_FILENO] = pipe_fd[P_IN];
	signal(SIGINT, ft_child_handler);
	signal(SIGQUIT, ft_child_handler);
	mini->pids[*i] = fork();
	if (mini->pids[*i] == 0)
	{
		signal(SIGTSTP, SIG_DFL);
		tmp_envp = ft_exctract_envp(mini);
		ft_redirect(tmp_cmd, pipe_fd);
		ft_find_path(mini, tmp_cmd->comand, tmp_envp);
	}
	++(*i);
}

static void	ft_in_cmd(t_mini *mini, t_cmd *tmp_cmd, int *i, int *pipe_fd)
{
	while (tmp_cmd)
	{
		if (!tmp_cmd->comand[0])
		{
			tmp_cmd = tmp_cmd->next;
			continue ;
		}
		pipe(pipe_fd);
		if (ft_check_builtin(tmp_cmd))
			ft_builtin(mini, tmp_cmd, pipe_fd);
		else
			ft_child_proc(mini, tmp_cmd, i, pipe_fd);
		close(pipe_fd[P_IN]);
		if (tmp_cmd->fd[0] != 0)
			close(tmp_cmd->fd[0]);
		if (tmp_cmd->fd[1] != 1)
			close(tmp_cmd->fd[1]);
		tmp_cmd = tmp_cmd->next;
	}
}

int	ft_proc(t_mini *mini)
{
	t_cmd	*tmp_cmd;
	int		i;
	int		j;
	int		pipe_fd[2];
	int		status;

	ft_add_pids(mini);
	i = 0;
	tmp_cmd = mini->cmd;
	ft_in_cmd(mini, tmp_cmd, &i, pipe_fd);
	close(pipe_fd[P_OUT]);
	close(pipe_fd[P_IN]);
	j = -1;
	while (++j < i)
	{
		waitpid(mini->pids[j], &status, 0);
		mini->error = WEXITSTATUS(status);
	}
	return (status);
}
