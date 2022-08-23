/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:28:20 by snino             #+#    #+#             */
/*   Updated: 2022/08/23 22:21:58 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_check_arg_add(t_mini *mini, char *res)
{
	t_list	*tmp_list;
	char 	*tmp;

	tmp = ft_strdup(res);
	if (ft_memchr(tmp, '=', ft_strlen(tmp)))
		*(char *)ft_memchr(tmp, '=', ft_strlen(tmp)) = '\0';
	tmp_list = ft_search_envp(mini->envp_list, tmp);
	free(tmp);
	if (tmp_list)
	{
		free(tmp_list->content);
		tmp_list->content = ft_strdup(res);
	}
	else
		ft_lstadd_back(&mini->envp_list, ft_lstnew(ft_strdup(res)));
}

//static void ft_error_export(t_mini *mini)
//{
//}
//
static void	ft_add_arg_export(t_mini *mini, t_cmd *cmd)
{
	t_list	*tmp_list;
	char	**args;
	char 	*tmp_str;
	char 	*res;
	int		i;

	i = 1;
	args = cmd->comand;
	tmp_list = mini->words_list_mod;
	while (args[i])
	{
		while (tmp_list && tmp_list->content != args[i])
			tmp_list = tmp_list->next;
		res = ft_strdup(args[i]);
		while (args[++i] && tmp_list->content && tmp_list->space == 0)
		{
			tmp_str =  ft_strcat(res, args[i]);
			free(res);
			res = ft_strdup(tmp_str);
			tmp_list = tmp_list->next;
		}
		ft_check_arg_add(mini, res);
		free(res);
	}
}

void	ft_export(t_mini *mini, t_cmd *cmd)
{
	if (cmd->comand[1])
		ft_add_arg_export(mini, cmd);
	else
		ft_print_export(mini, cmd->fd[1]);
}
