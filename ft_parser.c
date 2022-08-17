/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:25:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 16:18:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pars_redirect(t_mini *mini)
{
	t_cmd	*tmp;
	int		i;

	tmp = mini->cmd;
	while (tmp)
	{
		i = -1;
		while (tmp->comand[++i])
		{
			if ((!ft_memcmp(tmp->comand[i], ">", 2) \
			|| !ft_memcmp(tmp->comand[i], ">>", 3)) \
			&& ft_check_redirect_flag(mini, tmp->comand[i]))
				ft_pars_redirect_right(mini, tmp, i--);
			else if ((!ft_memcmp(tmp->comand[i], "<", 2) \
			|| !ft_memcmp(tmp->comand[i], "<<", 3)) \
			&& ft_check_redirect_flag(mini, tmp->comand[i]))
				ft_pars_redirect_left(mini, tmp, i--);
		}
		tmp = tmp->next;
	}
}

int	ft_parser(t_mini *mini)
{
	t_list	*tmp;
	t_cmd	*tmp_cmd;
	char	**cmd;
	int		i;

	tmp = mini->words_list_mod;
	tmp_cmd = NULL;
	while (tmp)
	{
		cmd = (char **) malloc(sizeof (char *) * ft_memory_num(tmp, "|", 2));
		i = -1;
		while (tmp && (ft_memcmp(tmp->content, "|", 2) || tmp->flag != 0))
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
	ft_pars_redirect(mini);
	return (mini->error);
}
