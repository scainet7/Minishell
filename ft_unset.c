/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:38:44 by snino             #+#    #+#             */
/*   Updated: 2022/08/22 14:09:15 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unset_error(char *var)
{
	ft_putstr_fd("username@minishell1: unset: ", 2);
	ft_putchar_fd('`', 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static int	valid_del_var(t_mini *mini, char *envp)
{
	int	i;

	if (!ft_isalpha(envp[0]))
		return (mini->error = unset_error(envp));
	i = 0;
	while (envp[++i] && envp[i] != '=')
	{
		if (!ft_isalnum(envp[i]))
			return (mini->error = unset_error(envp));
	}
	return (0);
}

void	ft_unset(t_mini *mini, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->comand[++i])
	{
		if (valid_del_var(mini, cmd->comand[i]))
			continue ;
		if (ft_search_envp(mini->envp_list, cmd->comand[i]))
			ft_search_envp(mini->envp_list, cmd->comand[i])->flag = 1;
	}
}
