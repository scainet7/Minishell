/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:25:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 15:23:34 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
