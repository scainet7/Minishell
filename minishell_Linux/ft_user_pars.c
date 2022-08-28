/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:15:57 by snino             #+#    #+#             */
/*   Updated: 2022/08/28 15:56:12 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_username_pars(t_mini *mini)
{
	t_list	*list;
	char	*tmp_str;
	char	*tmp;

	list = mini->envp_list;
	tmp_str = NULL;
	tmp = NULL;
	mini->username = NULL;
	if (ft_search_envp(list, "USER"))
	{
		list = ft_search_envp(list, "USER");
		if (list->flag == 0)
		{
			tmp_str = ft_strdup(list->content + 5);
			tmp = ft_strjoin(MAG"", tmp_str);
			mini->username = ft_strjoin(tmp, "@minishell: "END GRE);
			free(tmp_str);
			free(tmp);
		}
		else
			mini->username = ft_strdup(MAG"no_name@minishell: "END GRE);
	}
	else
		mini->username = ft_strdup(MAG"no_name@minishell: "END GRE);
}
