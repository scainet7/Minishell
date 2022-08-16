/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:44 by snino             #+#    #+#             */
/*   Updated: 2022/08/16 18:46:45 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_errno(t_mini *mini)
{
	t_list	*temp;

	temp = find_variable(mini->envp_list, "?");
	free(temp->content);
	temp->content = ft_strjoin_free("?=", ft_itoa(mini->error), 3);
	temp->flag = -1;
}

void	show(t_list *list, char *place)
{
	int		i;
	char	*tmp;
	int		ds;

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

void	show1(t_cmd *cmd, char *place)
{
	t_cmd	*temp;
	int		i;

	temp = cmd;
	printf("%s\n", place);
	while (temp)
	{
		i = -1;
		printf("SHOW:%d-> ", i + 2);
		while (temp->comand[++i])
			printf("'%s':%zu ", temp->comand[i], \
				(size_t)ft_strlen(temp->comand[i]));
		printf("| fd.in->%d fd.out->%d", cmd->fd[0], cmd->fd[1]);
		printf("\n");
		temp = temp->next;
	}
}
