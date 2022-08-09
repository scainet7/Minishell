/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:25:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/09 19:54:30 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_parser1(t_mini *mini)
{
	t_list		*tmp;
	t_cmd		*tmp_cmd;
	char 		**cmd;
	int 		i;

	tmp = mini->words_list;
	tmp_cmd = NULL;
	while (tmp)
	{
		cmd = (char **) malloc(sizeof (char *) * ft_memory_num(mini->words_list));
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
//void ft_parser2(t_mini *mini)
//{
//	t_list	*tmp_list;
//	char	**tmp;
//	char 	*buff;
//	int 	i;
//	int 	j;
//
//	while (mini->cmd)
//	{
//		i = 0;
//		j = 0;
//		tmp = mini->cmd->comand;
//		if (*tmp[i] != 34 && *tmp[i] != 39)
//
//		while (tmp)
//	}
//}