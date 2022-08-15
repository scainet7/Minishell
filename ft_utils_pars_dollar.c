/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars_dollar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:01:39 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 13:12:44 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_pars_chtoto(char *str)
{
	char	*tmp;
	char 	*buff;
	int 	i;
	int 	j;

	i = 0;
	j = -1;
	tmp = (char *)malloc(ft_strlen(str));
	while (ft_isalnum(tmp[++i]))
		tmp[++j] = tmp[i];
	tmp[++j] = '\0';
	buff = ft_strdup("snino");
	free(tmp);
	return (buff);
}

char 	*ft_pars_dollar(char *str)
{
	char	*tmp;
	int		i;
	int 	j;

	i = 1;
	while (ft_isalnum(str[i]))
		i++;
	tmp = (char *) malloc(i);
	j = 0;
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}