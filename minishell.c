/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:04:48 by snino             #+#    #+#             */
/*   Updated: 2022/08/07 21:41:03 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_save_username(t_mini *mini, char *envp)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strchr(envp, '=');
	tmp++;
	tmp2 = ft_strjoin(GRE, ft_strdup(tmp));
	mini->user = ft_strjoin(tmp2, GRE"@minishell$ "END);
}

void	ft_change_var(t_mini *mini, char *envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!ft_memcmp(envp, "OLDPWD=", 7))
		envp = ft_strdup("OLDPWD");
	else if (!ft_memcmp(envp, "SHLVL=", 6))
		envp = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(envp + 6) + 1), 3);
	else if (!ft_memcmp(envp, "PATH=", 5) && !ft_strnstr(envp, pwd, ft_strlen(envp)))
	{
		envp = ft_strjoin(envp, ":");
		envp = ft_strjoin_free(envp, getcwd(NULL, 1024), 6);
	}
	else if (!ft_memcmp(envp, "LOGNAME=", 8))
		ft_save_username(mini, envp);
	else
		envp = ft_strdup(envp);
	ft_lstadd_back(&mini->envp_list, ft_lstnew(envp));
	free(pwd);
}

void	ft_init(t_mini *mini, char **envp)
{
	int	i;

	i = 0;
	mini->exit_flag = 1;
	mini->envp_list = ft_lstnew(ft_strdup(envp[i]));
	while (envp[++i])
		ft_change_var(mini, envp[i]);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	char	*str;
	int		i;

	(void)argc;
	(void)argv;
	ft_init(&mini, envp);
	while (mini.exit_flag)
	{
		rl_replace_line("", 0);
		mini.line = readline(mini.user);
		if (mini.line && *mini.line)
			add_history(mini.line);
		if (mini.line && *mini.line)
			ft_parser(&mini);
		i = 0;
		while (mini.com_list != NULL)
		{
			str = mini.com_list->content;
			printf("%d ", i);
			printf("\033[31m%s\033[0m\n", str);
			mini.com_list = mini.com_list->next;
			i++;
		}
		i = 0;
		while (mini.words_list != NULL)
		{
			str = mini.words_list->content;
			printf("%d ", i);
			printf("\033[34m%s\033[0m\n", str);
			mini.words_list = mini.words_list->next;
			i++;
		}
		if (!mini.line)
		{
			mini.exit_flag = 0;
			printf("%s"BLU"exit\n"END, mini.user);
		}
		ft_freelst(mini.com_list);
		ft_freelst(mini.com_list);
	}
//	ft_freelst(mini.envp_list);
	return (0);
}
