/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:02:23 by snino             #+#    #+#             */
/*   Updated: 2022/08/24 18:05:23 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_mini *mini, t_cmd *cmd)
{
	char	*pwd;
	char	**tmp;
	int		i;

	i = 0;
	tmp = cmd->comand;
	if (tmp[i] && !tmp[i + 1])
	{
		pwd = getcwd(NULL, 1024);
		ft_putendl_fd(pwd, cmd->fd[STDOUT_FILENO]);
		free(pwd);
	}
	else
	{
		ft_putendl_fd(YEL"pwd: too many arguments"END, STDERR_FILENO);
		mini->error = 3;
	}
}
