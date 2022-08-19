/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:01:26 by snino             #+#    #+#             */
/*   Updated: 2022/08/19 19:02:09 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit_error(t_mini *mini, int error)
{
	if (error == 2)
	{
		ft_putstr_fd(MAG"username@minishell: "END \
		YEL"ERROR_MANY_ARGUMENTS\n"END, mini->cmd->fd[1]);
		mini->error = 3;
	}
	else if (error == 1)
	{
		ft_putstr_fd(MAG"username@minishell: "END \
		YEL"ERROR_ARGUMENTS_NOT_DIGIT\n"END, mini->cmd->fd[1]);
		mini->error = 3;
	}
}

static int	ft_check_digit(t_cmd *cmd)
{
	char	**tmp;
	char	*arg;
	int		i;

	tmp = cmd->comand;
	i = 0;
	while (tmp[i] != NULL)
		i++;
	arg = cmd->comand[i - 1];
	if (i == 2)
	{
		while (arg && *arg)
		{
			if (!ft_isdigit(*arg))
				return (1);
			++arg;
		}
		return (0);
	}
	else if (i > 2)
		return (2);
	return (0);
}

void	ft_exit(t_mini *mini, t_cmd *cmd)
{
	int	i;

	if (ft_check_digit(cmd) == 0 && !cmd->comand[1])
		exit(mini->error);
	else if (ft_check_digit(cmd) == 1 || ft_check_digit(cmd) == 2)
		ft_exit_error(mini, ft_check_digit(cmd));
	else if (ft_check_digit(cmd) == 0 && cmd->comand[1])
	{
		i = ft_atoi(cmd->comand[1]);
		exit(i);
	}
}
