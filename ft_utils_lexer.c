/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_wards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:49:42 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 22:00:14 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pars_words(t_mini *mini, char *line)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != ' ' && line[i] != 34 && line[i] != 39 && line[i] != 124 &&
		   line[i] != 60 && line[i] != 62 && line[i] != 38 && line[i] != 42)
		i++;
	buff = (char *) malloc(i);
	while (j < i && line[j] != '\0')
	{
		buff[j] = line[j];
		j++;
	}
	buff[i] = '\0';
	ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
	free(buff);
	return (&line[i]);
}

char	*ft_pars_quotes2(t_mini *mini, char *line)
{
	char	*buff;
	int		len;

	buff = ft_getword_mod(line, 34);
	ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
	ft_lstlast(mini->words_list)->flag = 1;
	len = ft_strlen(buff);
	free(buff);
	return (&line[len]);

}

char	*ft_pars_quotes(t_mini *mini, char *line)
{
	char	*buff;
	int		len;

	buff = ft_getword_mod(line, 39);
	ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
	ft_lstlast(mini->words_list)->flag = 1;
	len = ft_strlen(buff);
	free(buff);
	return (&line[len]);
}

char	*ft_pars_pipe(t_mini *mini, char *line)
{
	char	*buff;

	if (line[0] == 124 && line[1] == 124)
	{
		buff = (char *)malloc(3);
		buff[0] = 124;
		buff[1] = 124;
		buff[2] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[2]);
	}
	else if (line[0] == 124 && line[1] != 124)
	{
		buff = (char *)malloc(2);
		buff[0] = 124;
		buff[1] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[1]);
	}
	return (line);
}

char	*ft_pars_there(t_mini *mini, char *line)
{
	char	*buff;

	if (line[0] == 60 && line[1] == 60 && line[2] != 60)
	{
		buff = (char *)malloc(3);
		buff[0] = 60;
		buff[1] = 60;
		buff[2] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[2]);
	}
	else if (line[0] == 60 && line[1] != 60)
	{
		buff = (char *)malloc(2);
		buff[0] = 60;
		buff[1] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[1]);
	}
	else if (line[0] == 60 && line[1] == 60 && line[2] == 60)
		return (NULL);
	return (line);
}