/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:40:38 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 19:54:29 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	*ft_lex_quotes(t_mini *mini, char *line)
{
	if (ft_check_symbol(line) == 2)
		line = ft_pars_quotes2(mini, line);
	else if (ft_check_symbol(line) == 1)
		line = ft_pars_quotes(mini, line);
	else
		return (NULL);
	return (line);
}

void	ft_lexer(t_mini *mini)
{
	char	*line;

	line = mini->line;
	mini->words_list = NULL;
	while (line && *line)
	{
		while (line && *line && *line == ' ')
			line++;
		if (line && *line && (*line == 34 || *line == 39) && *line != ' ')
			line = ft_lex_quotes(mini, line);
		else if (line && *line && *line != ' ' && *line == 124)
			line = ft_pars_pipe(mini, line);
		else if (line && *line && *line != ' ' && *line == 60)
			line = ft_pars_there(mini, line);
		else if (line && *line && *line != ' ' && *line == 62)
			line = ft_pars_here(mini, line);
//		else if (line && *line && *line != ' ' && *line == 38)
//			line = ft_pars_and(mini, line);
//		else if (line && *line && *line != ' ' && *line == 42)
//			line = ft_pars_star(mini, line);
		else if(line && *line && *line != ' ')
			line = ft_pars_words(mini, line);
	}
}

void SHOW(t_mini *mini, char *place)
{
	int		i;
	char	*tmp;
	t_list 	*list;
	int 	ds;

	i = 0;
	printf("%s\n", place);
	list = mini->words_list;
	while (list)
	{
		tmp = list->content;
		ds = list->flag;
		printf("%d ", i);
		printf(BLU"%s "END RED"%d "END MAG"%d\n"END, tmp, ds, ft_strlen(tmp));
		list = list->next;
		i++;
	}
}
