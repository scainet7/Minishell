/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:40:38 by snino             #+#    #+#             */
/*   Updated: 2022/08/10 17:43:32 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	*ft_pars_quotes(t_mini *mini, char *line)
{
	if (ft_check_symbol(line) == 2)
		line = ft_pars_words1(mini, line);
	else if (ft_check_symbol(line) == 1)
		line = ft_pars_words2(mini, line);
	else
		return (NULL);
	return (line);
}

void	ft_parser(t_mini *mini)
{
	char	*line;

	line = mini->line;
	while (line && *line)
	{
		while (line && *line && *line == ' ')
			line++;
		if (line && *line && (*line == 34 || *line == 39) && *line != ' ')
			line = ft_pars_quotes(mini, line);
		else if (line && *line && *line != ' ' && *line == 124)
			line = ft_pars_words3(mini, line);
		else if (line && *line && *line != ' ' && *line == 60)
			line = ft_pars_words4(mini, line);
		else if (line && *line && *line != ' ' && *line == 62)
			line = ft_pars_words5(mini, line);
		else if (line && *line && *line != ' ' && *line == 38)
			line = ft_pars_words6(mini, line);
		else if (line && *line && *line != ' ' && *line == 42)
			line = ft_pars_words7(mini, line);
		else if(line && *line && *line != ' ')
			line = ft_pars_cmd(mini, line);
	}
	ft_parser1(mini);
	ft_parser2(mini);
}

void SHOW(t_mini *mini)
{
	int		i;
	char	*tmp;

	i = 0;
	while (mini->words_list)
	{
		tmp = mini->words_list->content;
		printf("%d ", i);
		printf(BLU"%s "END MAG"%d\n"END, tmp, ft_strlen(tmp));
		mini->words_list = mini->words_list->next;
		i++;
	}
}
