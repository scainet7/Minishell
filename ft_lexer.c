/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:40:38 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 12:55:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	*ft_lex_quotes(t_mini *mini, char *line)
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
			line = ft_pars_symb(mini, line, 124);
		else if (line && *line && *line != ' ' && *line == 60)
			line = ft_pars_symb(mini, line, 60);
		else if (line && *line && *line != ' ' && *line == 62)
			line = ft_pars_symb(mini, line, 62);
		else if (line && *line && *line != ' ' && (*line == 38 || *line == 42))
			line = ft_pars_star_and(mini, line);
		else if(line && *line && *line != ' ')
			line = ft_pars_words(mini, line);
	}
	SHOW(mini->words_list, "lexer: ");
	if (!mini->error)
		ft_lexer2(mini);
	else
		printf(RED"ERROR\n"END);
	SHOW(mini->words_list_mod, "lexer2: ");
}

void 	ft_lexer2(t_mini *mini)
{
	t_list	*list;
	char 	*tmp;
	char	*buff;

	list = mini->words_list;
	mini->words_list_mod = NULL;
	while (list)
	{
		tmp = list->content;
		if (list->flag == 1)
			buff = ft_strdup(tmp);
		if (list->flag == 2)
			buff = ft_check_dollar(tmp, buff);
//			buff = ft_strdup(tmp);
		if (list->flag == 0)
			buff = ft_check_dollar(tmp, buff);
//			buff = ft_strdup(tmp);
		ft_lstadd_back(&mini->words_list_mod, ft_lstnew(ft_strdup(buff)));
		if (list->flag == 1)
			ft_lstlast(mini->words_list_mod)->flag = 1;
		else if (list->flag == 2)
			ft_lstlast(mini->words_list_mod)->flag = 2;
		else
			ft_lstlast(mini->words_list_mod)->flag = 0;
		list = list->next;
		free(buff);
	}
}

void SHOW(t_list *list, char *place)
{
	int		i;
	char	*tmp;
	int 	ds;

	i = 0;
	printf("%s\n", place);
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
