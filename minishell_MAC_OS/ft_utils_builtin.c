/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:50:16 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 17:50:16 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_builtin(t_cmd *cmd)
{
	if (cmd && !ft_memcmp(cmd->comand[0], "echo", 5))
		return (1);
	else if (cmd && !ft_memcmp(cmd->comand[0], "env", 4))
		return (1);
	else if (cmd && !ft_memcmp(cmd->comand[0], "pwd", 4))
		return (1);
	else if (cmd && !ft_memcmp(cmd->comand[0], "unset", 6))
		return (1);
	else if (cmd && !ft_memcmp(cmd->comand[0], "cd", 3))
		return (1);
	else if (cmd && !ft_memcmp(cmd->comand[0], "export", 7))
		return (1);
	else if (cmd && !ft_memcmp(cmd->comand[0], "exit", 5))
		return (1);
	return (0);
}
