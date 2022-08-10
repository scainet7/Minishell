/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:43:13 by snino             #+#    #+#             */
/*   Updated: 2022/08/10 16:42:54 by snino            ###   ########.fr       */
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

int	ft_memory_num(t_list *words_list)
{
	t_list	*tmp;
	int		count;

	tmp = words_list;
	count = 1;
	while (tmp)
	{
		if (!ft_memcmp(tmp->content, "|", 2))
			break ;
		++count;
		tmp = tmp->next;
	}
	return (count);
}

int	ft_check_symbol(char *line)
{
	if (line[0] == 39 && ft_strchr(++line, 39))
		return (1);
	else if (line[0] == 34 && ft_strchr(++line, 34))
		return (2);
	else
		printf(RED"ERROR_NO_CLOSED_KOVICHKA\n"END);
	return (0);
}

 void	SHOW1(t_cmd *cmd, char *place)
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
 			printf("'%s':%zu ", temp->comand[i], (size_t)ft_strlen(temp->comand[i]));
 		printf("| fd.in->%d fd.out->%d", cmd->fd[0], cmd->fd[1]);
 		printf("\n");
 		temp = temp->next;
 	}
 }