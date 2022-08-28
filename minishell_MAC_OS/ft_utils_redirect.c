/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:19:48 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 16:46:00 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_heredoc(t_cmd *tmp, int i)
{
	char	**cmd;
	char	*hd;
	char	*line;
	int		p[2];

	hd = NULL;
	cmd = tmp->comand;
	rl_replace_line("", 0);
	line = readline("> ");
	while (line && (!ft_strnstr(cmd[i + 1], line, ft_strlen(line)) || !*line))
	{
		hd = ft_strjoin_free(hd, line, 6);
		hd = ft_strjoin_free(hd, "\n", 2);
		line = readline("> ");
	}
	free(line);
	pipe(p);
	ft_putstr_fd(hd, p[P_IN]);
	free(hd);
	close(p[P_IN]);
	tmp->fd[0] = p[0];
}

void	ft_pars_redirect_left(t_mini *mini, t_cmd *tmp, int i)
{
	int		fd;
	char	**cmd;

	cmd = tmp->comand;
	if (cmd[i][1] == '<')
		ft_heredoc(tmp, i);
	else
	{
		fd = open(cmd[i + 1], O_RDONLY, 0644);
		if (fd == -1)
		{
			if (tmp->fd[0] != 0)
				close(tmp->fd[0]);
			ft_pars_error(mini, cmd[i + 1], 3);
			tmp ->comand[0] = NULL;
		}
		else
		{
			if (tmp->fd[0] != 0)
				close(tmp->fd[0]);
			tmp->fd[0] = fd;
		}
	}
	while (cmd[++i])
		cmd[i - 1] = cmd[i + 1];
}

void	ft_pars_redirect_right(t_mini *mini, t_cmd *tmp, int i)
{
	int		fd;
	char	**cmd;

	cmd = tmp->comand;
	if (cmd[i][1] == '>')
		fd = open(cmd[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(cmd[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		ft_pars_error(mini, cmd[i + 1], 3);
		tmp->comand[0] = NULL;
	}
	else
	{
		if (tmp->fd[1] != 1)
			close(tmp->fd[1]);
		tmp->fd[1] = fd;
	}
	while (cmd[++i])
		cmd[i - 1] = cmd[i + 1];
}

int	ft_check_redirect_flag(t_mini *mini, char *cmd)
{
	t_list	*tmp_list;
	char	*tmp;

	tmp_list = mini->words_list_mod;
	tmp = NULL;
	while (tmp_list)
	{
		tmp = tmp_list->content;
		if (!ft_memcmp(tmp, cmd, ft_strlen(tmp) + 1) && tmp_list->flag == 0)
			return (1);
		tmp_list = tmp_list->next;
	}
	return (0);
}
