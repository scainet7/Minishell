/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:37:15 by snino             #+#    #+#             */
/*   Updated: 2022/08/19 14:35:14 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show(t_list *list, char *place)
{
	int		i;
	char	*tmp;
	int		fl;
	int		sp;

	i = 0;
	printf("%s\n", place);
	while (list)
	{
		tmp = list->content;
		fl = list->flag;
		sp = list->space;
		printf("%d ", i);
		printf(BLU"%s "END RED"flag %d "END RED"space %d "END MAG"%d\n"END, \
				tmp, fl, sp, ft_strlen(tmp));
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
