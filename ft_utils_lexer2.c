/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_words1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:16:23 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 13:14:38 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char 	*ft_check_dollar(char *str, char *buff)
{
	if (ft_strchr(str, '$'))
	{
		buff = ft_split_dollar(str, buff);
	}
	else
		buff = ft_strdup(str);
	return (buff);
}

char 	*ft_split_dollar(char *str, char *buff)
{
	t_list	*tmp_list;
	char	*tmp_str;
	char 	*tmp;
	char	*res;

	tmp_str = str;
	tmp_list = NULL;
	while (*tmp_str != '\0')
	{
		ft_lstadd_back(&tmp_list, ft_lstnew(ft_strcdup(tmp_str, '$')));
		tmp_str = ft_strchr(tmp_str, '$');
		tmp = ft_pars_dollar(tmp_str);
		res = ft_pars_chtoto(tmp);
		ft_lstadd_back(&tmp_list, ft_lstnew(ft_strdup(res)));
		tmp_str = &tmp_str[ft_strlen(tmp)];
		printf("%s\n", tmp_str);
		if (!ft_strchr(tmp_str, '$') && *tmp_str != '\0')
		{
			ft_lstadd_back(&tmp_list, ft_lstnew(ft_strdup(tmp_str)));
			tmp_str = ft_strchr(tmp_str, '\0');
		}
		free(tmp);
		free(res);
	}
	SHOW(tmp_list, "split_dollar: ");
	buff = ft_join_dollar(tmp_list, buff);
	return (buff);
}

char 	*ft_join_dollar(t_list *list, char *buff)
{
	t_list	*tmp_list;
	char	*tmp;
	char	*res;
	int 	len;

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
	buff = ft_strdup(res);
	free(res);
	ft_freelst(list);
	return (buff);
}
//
//char 	*ft_pars_dollar(char *str, char *buff)
//{
//	t_list	*tmp_list;
//	char	*tmp;
//	char 	*res;
//	char 	*s1;
//	char 	*s2;
//	int 	i;
//	int 	j;
//
//	tmp = str;
//	res = ft_strcdup(tmp, '$');
//	tmp = ft_strchr(tmp, '$');
//	i = 1;
//	while (ft_isalnum(tmp[i]))
//		i++;
//	s1 = (char *) malloc(i + 1);
//	j = 0;
//	while (j < i)
//	{
//		s1[j] = tmp[j];
//		j++;
//	}
//	s1[i] = '\0';
//	tmp = &tmp[i];
//	printf("%s %d\n", s1, ft_strlen(s1));
//	printf("%s %d\n", tmp, ft_strlen(tmp));
//	s2 = ft_pars_chtoto(s1);
//	buff = ft_strjoin(res, s2);
//	free(res);
//	free(s1);
//	free(s2);
//	return (buff);
//}