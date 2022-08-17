/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:43:13 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 15:03:00 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmd_new(void *cmd)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->comand = cmd;
	new_cmd->fd[0] = 0;
	new_cmd->fd[1] = 1;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!cmd || !new)
		return ;
	last = *cmd;
	if (!last)
		*cmd = new;
	else
	{
		while (last -> next)
			last = last -> next;
		last -> next = new;
	}
}

int	ft_memory_num(t_list *words_list, char *symbol, int len)
{
	t_list	*tmp;
	int		count;

	tmp = words_list;
	count = 1;
	while (tmp)
	{
		if (!ft_memcmp(tmp->content, symbol, len) && tmp->flag == 0)
			break ;
		++count;
		tmp = tmp->next;
	}
	return (count);
}

void	free_tcmd(t_cmd *cmd)
{
	t_cmd	*temp;

	while (cmd)
	{
		temp = cmd->next;
		free(cmd->comand);
		free(cmd);
		cmd = temp;
	}
}

int	ft_pars_error(t_mini *mini, char *file, int error)
{
	if (error == 1)
		ft_putstr_fd("shell: syntax error near unexpected token `newline'\n", 2);
	else if (error == 2)
		ft_putstr_fd("shell: syntax error near unexpected token `|'\n", 2);
	if (error == 1 || error == 2)
		return (258);
	if (error == 3)
	{
		ft_putstr_fd("shell: ", 2);
		perror(file);
		mini->error = 1;
	}
	return (1);
}
