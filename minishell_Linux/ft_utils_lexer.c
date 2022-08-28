/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:36:10 by snino             #+#    #+#             */
/*   Updated: 2022/08/19 14:49:43 by snino            ###   ########.fr       */
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
	while (line[i] != '\0' && line[i] != ' ' && line[i] != 34 && line[i] != 39 \
		&& line[i] != 124 && line[i] != 60 && line[i] != 62 && line[i] != 38 \
		&& line[i] != 42)
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
	if (line[i] == ' ')
		ft_lstlast(mini->words_list)->space = 1;
	return (&line[i]);
}

int	ft_check_symbol(char *line)
{
	if (line[0] == 39 && ft_strchr(++line, 39))
		return (1);
	else if (line[0] == 34 && ft_strchr(++line, 34))
		return (2);
	return (0);
}

char	*ft_pars_quotes(t_mini *mini, char *line, char c)
{
	char	*buff;
	int		len;

	buff = ft_getword_mod(line, c);
	ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
	if (c == 34)
		ft_lstlast(mini->words_list)->flag = 2;
	else
		ft_lstlast(mini->words_list)->flag = 1;
	len = ft_strlen(buff) + 2;
	free(buff);
	if (line[len] == ' ')
		ft_lstlast(mini->words_list)->space = 1;
	return (&line[len]);
}

char	*ft_pars_symb(t_mini *mini, char *line, char c)
{
	char	*buff;

	if (line[0] == c && line[1] == c && line[2] != c)
	{
		buff = (char *)malloc(3);
		buff[0] = c;
		buff[1] = c;
		buff[2] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[2]);
	}
	else if (line[0] == c && line[1] != c)
	{
		buff = (char *)malloc(2);
		buff[0] = c;
		buff[1] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[1]);
	}
	else if (line[0] == c && line[1] == c && line[3] == c)
		mini->error = 2;
	return (NULL);
}
