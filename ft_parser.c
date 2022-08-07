/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:40:38 by snino             #+#    #+#             */
/*   Updated: 2022/08/07 21:37:21 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_symbol(char line)
{
	if (line == 34)
		return (1);
	else if (line == 39)
		return (0);
	return (0);
}

char	*ft_pars_words1(t_mini *mini, char *line)
{
	char	*buff;
	char	*tmp;
	int		i;

	tmp = ft_strchr(++line, 34);
	if (!tmp)
	{
		printf(RED"ERROR_NO_CLOSED_KOVICHKA\n"END);
		return (NULL);
	}
	else
	{
		i = -1;
		while (line[++i] != 34)
			;
		buff = (char *)malloc(i + 1);
		i = -1;
		while (line[++i] != 34)
			buff[i] = line[i];
		buff[i] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
	}
	return (&line[i + 1]);
}

char	*ft_pars_words2(t_mini *mini, char *line)
{
	char	*buff;
	char	*tmp;
	int		i;

	tmp = ft_strchr(++line, 39);
	if (!tmp)
	{
		printf(RED"ERROR_NO_CLOSED_KOVICHKA\n"END);
		return (NULL);
	}
	else
	{
		i = -1;
		while (line[++i] != 39)
			;
		buff = (char *)malloc(i + 1);
		i = -1;
		while (line[++i] != 39)
			buff[i] = line[i];
		buff[i] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
	}
	return (&line[i + 1]);
}

char	*ft_pars_cmd(t_mini *mini, char *line)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != ' ' && line[i] != 34 && line[i] != 39)
		i++;
	buff = (char *) malloc(i);
	while (j < i && line[j] != '\0')
	{
		buff[j] = line[j];
		j++;
	}
	buff[i] = '\0';
	ft_lstadd_back(&mini->com_list, ft_lstnew(ft_strdup(buff)));
	free(buff);
	return (&line[i]);
}

void	ft_parser(t_mini *mini)
{
	char	*line;
	char	*var;

	line = mini->line;
	while (line && *line)
	{
		while (line && *line && *line == ' ')
			line++;
		var = line;
		line = var;
		if (line && *line && (*line == 34 || *line == 39))
		{
			if (ft_check_symbol(line[0]))
				line = ft_pars_words1(mini, line);
			else
				line = ft_pars_words2(mini, line);
		}
		else
			line = ft_pars_cmd(mini, line);
	}
}
