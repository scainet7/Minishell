/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:25:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 16:21:13 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(t_cmd *tmp, int i)
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

void	ft_pars_redirect(t_mini *mini)
{
	t_cmd	*tmp;
	int		i;

	tmp = mini->cmd;
	while (tmp)
	{
		i = -1;
		while (tmp->comand[++i])
		{
			if (!ft_memcmp(tmp->comand[i], ">", 2) \
			|| !ft_memcmp(tmp->comand[i], ">>", 3))
				ft_pars_redirect_right(mini, tmp, i--);
			else if (!ft_memcmp(tmp->comand[i], "<", 2) \
			|| !ft_memcmp(tmp->comand[i], "<<", 3))
				ft_pars_redirect_left(mini, tmp, i--);
		}
		tmp = tmp->next;
	}
}

void	ft_parser(t_mini *mini)
{
	t_list	*tmp;
	t_cmd	*tmp_cmd;
	char	**cmd;
	int		i;

	tmp = mini->words_list;
	tmp_cmd = NULL;
	while (tmp)
	{
		cmd = (char **) malloc(sizeof (char *) * ft_memory_num(tmp, "|", 2));
		i = -1;
		while (tmp && ft_memcmp(tmp->content, "|", 2))
		{
			cmd[++i] = tmp->content;
			tmp = tmp->next;
		}
		cmd[++i] = NULL;
		ft_cmdadd_back(&tmp_cmd, ft_cmd_new(cmd));
		if (tmp)
			tmp = tmp->next;
	}
	mini->cmd = tmp_cmd;
	ft_pars_redirect(mini);
}

void	show1(t_cmd *cmd, char *place)
{
	t_cmd	*temp;
	int		i;

	temp = cmd;
	printf("%s\n", place);
	while (temp)
	{
		i = -1;
		printf("SHOW:%d-> ", i + 2);
		while (temp->comand[++i])
			printf("'%s':%zu ", temp->comand[i], \
				(size_t)ft_strlen(temp->comand[i]));
		printf("| fd.in->%d fd.out->%d", cmd->fd[0], cmd->fd[1]);
		printf("\n");
		temp = temp->next;
	}
}
