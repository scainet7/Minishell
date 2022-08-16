/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_words1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:16:23 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 14:21:48 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_join_dollar(t_list *list)
{
	t_list	*tmp_list;
	char	*tmp;
	char	*res;
	int		len;

	len = 1;
	tmp_list = list;
	while (tmp_list)
	{
		tmp = tmp_list->content;
		len = len + ft_strlen(tmp);
		tmp_list = tmp_list->next;
	}
	tmp_list = list;
	res = (char *)malloc(len + 1);
	res[0] = '\0';
	while (tmp_list)
	{
		tmp = tmp_list->content;
		res = ft_strcat(res, tmp);
		tmp_list = tmp_list->next;
	}
	ft_freelst(list);
	return (res);
}

static char	*ft_split_dollar(t_mini *mini, char *str, char *buff)
{
	t_list	*tmp_list;
	char	*tmp_str;
	char	*tmp;
	char	*res;

	tmp_str = str;
	tmp_list = NULL;
	while (*tmp_str != '\0')
	{
		ft_lstadd_back(&tmp_list, ft_lstnew(ft_strcdup(tmp_str, '$')));
		tmp_str = ft_strchr(tmp_str, '$');
		tmp = ft_pars_dollar(tmp_str);
		res = ft_pars_envp(mini, tmp);
		ft_lstadd_back(&tmp_list, ft_lstnew(ft_strdup(res)));
		tmp_str = &tmp_str[ft_strlen(tmp)];
		if (!ft_strchr(tmp_str, '$') && *tmp_str != '\0')
		{
			ft_lstadd_back(&tmp_list, ft_lstnew(ft_strdup(tmp_str)));
			tmp_str = ft_strchr(tmp_str, '\0');
		}
		free(tmp);
		free(res);
	}
	buff = ft_join_dollar(tmp_list);
	return (buff);
}

char	*ft_check_dollar(t_mini *mini, char *str, char *buff)
{
	if (ft_strchr(str, '$'))
		buff = ft_split_dollar(mini, str, buff);
	else
		buff = ft_strdup(str);
	return (buff);
}
