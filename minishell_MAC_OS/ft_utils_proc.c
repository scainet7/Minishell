/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:17:24 by snino             #+#    #+#             */
/*   Updated: 2022/08/16 17:44:12 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect(t_cmd *tmp_cmd, int *pipe_fd)
{
	if (tmp_cmd->fd[STDIN_FILENO] != STDIN_FILENO)
	{
		dup2(tmp_cmd->fd[STDIN_FILENO], STDIN_FILENO);
		close(tmp_cmd->fd[STDIN_FILENO]);
	}
	if (tmp_cmd->fd[STDOUT_FILENO] != STDOUT_FILENO)
	{
		dup2(tmp_cmd->fd[STDOUT_FILENO], STDOUT_FILENO);
		close(tmp_cmd->fd[STDOUT_FILENO]);
	}
	close(pipe_fd[P_IN]);
	close(pipe_fd[P_OUT]);
}

char	**ft_exctract_envp(t_mini *mini)
{
	int		l;
	int		i;
	char	**tmp;
	t_list	*tmp_list;

	tmp_list = mini->envp_list;
	l = ft_lstsize(tmp_list);
	tmp = malloc(sizeof(char *) * l + 1);
	if (!tmp)
		return (NULL);
	i = -1;
	while (tmp_list)
	{
		if (!tmp_list->flag)
			tmp[++i] = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	ft_add_pids(t_mini *mini)
{
	int		i;
	t_cmd	*tmp_cmd;

	mini->num_cmd = 0;
	tmp_cmd = mini->cmd;
	while (tmp_cmd)
	{
		mini->num_cmd++;
		tmp_cmd = tmp_cmd->next;
	}
	i = -1;
	mini->pids = malloc(sizeof(int) * (mini->num_cmd));
	if (!mini->pids)
		exit(1);
	while (++i < mini->num_cmd)
	{
		mini->pids[i] = 0;
	}
}
