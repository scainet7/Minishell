/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_dollar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:01:39 by snino             #+#    #+#             */
/*   Updated: 2022/08/22 14:17:22 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_trim_envp(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '=');
	tmp = &tmp[1];
	return (tmp);
}

static char	*ft_check_envplist(t_mini *mini, char *str)
{
	t_list	*tmp_list;
	char	*buff;
	char	*tmp_str;
	char	*tmp;

	tmp = &str[1];
	tmp_list = mini->envp_list;
	buff = NULL;
	while (tmp_list)
	{
		tmp_str = tmp_list->content;
		if (!ft_memcmp(tmp_str, tmp, ft_strlen(tmp)) \
			&& tmp_list->flag != 1)
		{
			buff = ft_trim_envp(tmp_str);
			break ;
		}
		else
			tmp_list = tmp_list->next;
	}
	if (buff == NULL)
		buff = "";
	return (buff);
}

char	*ft_pars_envp(t_mini *mini, char *str)
{
	char	*buff;

	if (ft_strlen(str) == 1)
		buff = ft_strdup("$");
	else
		buff = ft_strdup(ft_check_envplist(mini, str));
	return (buff);
}

char	*ft_pars_dollar(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	if (str[i] != '?')
		while (ft_isalnum(str[i]))
			i++;
	else
		i++;
	tmp = (char *) malloc(i);
	j = 0;
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
