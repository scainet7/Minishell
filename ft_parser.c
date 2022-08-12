/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:25:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 20:10:08 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_parser(t_mini *mini)
{
	t_list		*tmp;
	t_cmd		*tmp_cmd;
	char 		**cmd;
	int 		i;

	tmp = mini->words_list;
	tmp_cmd = NULL;
	while (tmp)
	{
		cmd = (char **) malloc(sizeof (char *) * ft_memory_num(tmp, "|"));
		i = -1;
		while (tmp && ft_memcmp(tmp->content, "|", 2))
		{
			cmd[++i] = tmp->content;;
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
//	t_cmd *tmp_cmd;
//	t_cmd *res;
//	t_list *tmp_list;
//	char **tmp;
//	char *cmd;
//	char *buff;
//	int i;
//
//	tmp_cmd = mini->cmd;
//	tmp_list = NULL;
//	res = NULL;
//	while (tmp_cmd)
//	{
//		i = 0;
//		while (tmp_cmd->comand[i] != NULL)
//		{
//			cmd = tmp_cmd->comand[i];
//			if (cmd[0] == 34)
//				buff = ft_strcdup(&cmd[1], 34);
//			else if (cmd[0] == 39)
//				buff = ft_strcdup(cmd, 39);
//			else
//				buff = ft_strdup(cmd);
//			ft_lstadd_back(&tmp_list, ft_lstnew(ft_strdup(buff)));
//			free(buff);
//			i++;
//		}
//		SHOW2(tmp_list, "parser:\n");
////		while (tmp_list)
////		{
////			tmp = (char **)malloc(sizeof (char *) * ft_memory_num(tmp_list, NULL));
////			i = -1;
////			while (tmp_list && ft_memcmp(tmp_list->content, NULL, 4))
////			{
////				tmp[++i] = tmp_list->content;
////				tmp_list = tmp_list->next;
////			}
////			tmp[++i] = NULL;
////			ft_cmdadd_back(&res, ft_cmd_new(cmd));
////			if (tmp_list)
////				tmp_list = tmp_list->next;
////		}
////		ft_freelst(tmp_list);
////		tmp_cmd = tmp_cmd->next;
////		SHOW1(mini->cmd);
//	}
////	mini->cmd = res;
//}

void SHOW2(t_list *list, char *place)
{
	int		i;
	int 	ds;
	char	*tmp;

	printf("%s\n", place);
	i = 0;
	while (list)
	{
		tmp = list->content;
		ds = list->flag;
		printf("%d ", i);
		printf(GRE"%s " "%d " "%d\n"END, tmp, ds, ft_strlen(tmp));
		list = list->next;
		i++;
	}
}