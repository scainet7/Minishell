/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_words1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:16:23 by snino             #+#    #+#             */
/*   Updated: 2022/08/12 22:02:13 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pars_and(t_mini *mini, char *line)
{
	char	*buff;

	if (line[0] == 38 && line[1] == 38)
	{
		buff = (char *)malloc(3);
		buff[0] = 38;
		buff[1] = 38;
		buff[2] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));
		free(buff);
		return (&line[2]);
	}
	return (line);
}

char	*ft_pars_star(t_mini *mini, char *line)
{
	char	*buff;

	if (line[0] == 42)
	{
		buff = (char *)malloc(2);
		buff[0] = 42;
		buff[1] = '\0';
		ft_lstadd_back(&mini->words_list, ft_lstnew(ft_strdup(buff)));

		free(buff);
		return (&line[1]);
	}
	return (line);
}