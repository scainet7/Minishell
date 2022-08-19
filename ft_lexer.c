/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:40:38 by snino             #+#    #+#             */
/*   Updated: 2022/08/19 14:46:35 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_lex_quotes(t_mini *mini, char *line)
{
	if (ft_check_symbol(line) == 2)
		line = ft_pars_quotes(mini, line, 34);
	else if (ft_check_symbol(line) == 1)
		line = ft_pars_quotes(mini, line, 39);
	else
	{
		mini->error = 1;
		return (NULL);
	}
	return (line);
}

static void	ft_lex_symbols(t_mini *mini)
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
			line = ft_pars_symb(mini, line, 124);
		else if (line && *line && *line != ' ' && *line == 60)
			line = ft_pars_symb(mini, line, 60);
		else if (line && *line && *line != ' ' && *line == 62)
			line = ft_pars_symb(mini, line, 62);
		else if (line && *line && *line != ' ')
			line = ft_pars_words(mini, line);
	}
}

static void	ft_lexer2(t_mini *mini)
{
	t_list	*list;
	char	*tmp;
	char	*buff;

	list = mini->words_list;
	mini->words_list_mod = NULL;
	while (list)
	{
		tmp = list->content;
		if (list->flag == 1)
			buff = ft_strdup(tmp);
		else if (list->flag == 2)
			buff = ft_check_dollar(mini, tmp, buff);
		else if (list->flag == 0)
			buff = ft_check_dollar(mini, tmp, buff);
		ft_lstadd_back(&mini->words_list_mod, ft_lstnew(ft_strdup(buff)));
		ft_check_flag(mini, list);
		ft_check_space(mini, list);
		list = list->next;
		free(buff);
	}
}

int	ft_lexer(t_mini *mini)
{
	ft_lex_symbols(mini);
	if (!mini->error)
		ft_lexer2(mini);
	else
		return (ft_pars_error(mini, NULL, mini->error));
	return (mini->error);
}
