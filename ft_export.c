/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:28:20 by snino             #+#    #+#             */
/*   Updated: 2022/08/22 22:11:13 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_check_array(char **tmp_envp, char *str)
{
	int	i;

	i = -1;
	while (tmp_envp[++i])
		if (tmp_envp[i] == str)
			return (1);
	return (0);
}

void ft_move_print(char *tmp, int fd)
{
	char	*str;
//	char 	*tmp_str;
//	int 	len;

	str = ft_strdup(tmp);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\n", fd);
	free(str);
}

static t_list	*ft_parser_export_list(t_list *list, char **tmp_envp)
{
	t_list	*res;
	char	*str;

	res = list;
	str = NULL;
	while (list)
	{
		if (ft_check_array(tmp_envp, res->content))
			res = list;
		str = ft_strdup(list->content);
		if (ft_memchr(str, '=', ft_strlen(str)))
			*(char *)ft_memchr(str, '=', ft_strlen(str)) = '\0';
		if (ft_strncmp(str, (char *)res->content, ft_strlen(str) + 1) < 0 \
			&& !ft_check_array(tmp_envp, (char *)list->content))
			res = list;
		list = list->next;
		free(str);
	}
	return (res);
}

static void	ft_print_export(t_mini *mini, int fd)
{
	t_list	*tmp_list;
	int 	i;
	char	*tmp_envp[1000];

	i = -1;
	while (++i < 1000)
		tmp_envp[i] = NULL;
	i = -1;
	while (1)
	{
		tmp_list = ft_parser_export_list(mini->envp_list, tmp_envp);
		if (ft_check_array(tmp_envp, (char *)tmp_list->content))
			break ;
		if (tmp_list->flag == 0)
			ft_move_print(tmp_list->content, fd);
		tmp_envp[++i] = (char *)tmp_list->content;
	}
}

void	ft_export(t_mini *mini, t_cmd *cmd)
{
	if (cmd->comand[1])
		;
	else
		ft_print_export(mini, cmd->fd[1]);
}
