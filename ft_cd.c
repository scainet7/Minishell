/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:22:39 by snino             #+#    #+#             */
/*   Updated: 2022/08/18 19:03:25 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_path_dir(t_mini *mini, t_cmd *cmd)
{
	char	*buff;

	if (!cmd->comand[1])
		buff = ft_strdup(mini->home);
	else if (!ft_memcmp(cmd->comand[1], "/", 2))
		buff = ft_strdup(cmd->comand[1]);
	else
	{
		buff = ft_strjoin_free(getcwd(NULL, 1024), "/", 2);
		buff = ft_strjoin_free(buff, cmd->comand[1], 2);
	}
	return (buff);
}

void ft_cd(t_mini * mini, t_cmd *cmd)
{
	t_list	*tmp_list;
	char	*dirrectory;

	dirrectory = ft_path_dir(mini, cmd);
	if (!chdir(dirrectory))
	{
		tmp_list = ft_search_envp(mini->envp_list, "OLDPWD");
		tmp_list->flag = 1;
		free(tmp_list->content);
		tmp_list->content = ft_strjoin_free("OLDPWD=", getcwd(NULL, 1024), 3);
		tmp_list = ft_search_envp(mini->envp_list, "PWD");
		tmp_list->flag = 1;
		free(tmp_list->content);
		tmp_list->content = ft_strjoin_free("PWD=", getcwd(NULL, 1024), 3);
	}
	else
	{
		ft_putstr_fd(YEL"cd: "END, 0);
		perror(mini->words_list_mod->next->content);
	}
	free(dirrectory);
}
