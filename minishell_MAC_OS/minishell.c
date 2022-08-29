/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:04:48 by snino             #+#    #+#             */
/*   Updated: 2022/08/29 18:12:24 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_line_lst_cmd(t_mini *mini)
{
	ft_signal();
	if (mini->line && *mini->line != '\0')
		change_errno(mini);
	if (mini->line && *mini->line && (mini->error == 0 || mini->error == 3 \
		|| mini->error == 127))
	{
		ft_freelst(mini->words_list);
		ft_freelst(mini->words_list_mod);
		free_tcmd(mini->cmd);
	}
	else if (mini->line && *mini->line && mini->error == 1)
		ft_freelst(mini->words_list);
	if (mini->pids)
		free(mini->pids);
	mini->pids = NULL;
	mini->error = 0;
	free(mini->username);
	free(mini->line);
}

static void	ft_check_envp(t_list *envp)
{
	if (!ft_search_envp(envp, "PWD"))
		ft_lstadd_back(&envp, ft_lstnew(ft_strdup("PWD")));
	if (!ft_search_envp(envp, "OLDPWD"))
		ft_lstadd_back(&envp, ft_lstnew(ft_strdup("OLDPWD")));
	if (!ft_search_envp(envp, "SHLVL"))
		ft_lstadd_back(&envp, ft_lstnew(ft_strdup("SHLVL=1")));
}

static void	ft_change_envp(t_mini *mini, char *envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!ft_memcmp(envp, "OLDPWD=", 7))
		envp = ft_strdup("OLDPWD");
	else if (!ft_memcmp(envp, "SHLVL=", 6))
		envp = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(envp + 6) + 1), 3);
	else if (!ft_memcmp(envp, "PATH=", 5) \
			&& !ft_strnstr(envp, pwd, ft_strlen(envp)))
	{
		envp = ft_strjoin(envp, ":");
		envp = ft_strjoin_free(envp, getcwd(NULL, 1024), 6);
	}
	else
		envp = ft_strdup(envp);
	ft_lstadd_back(&mini->envp_list, ft_lstnew(envp));
	free(pwd);
}

static void	ft_init(t_mini *mini, char **envp)
{
	int	i;

	i = 0;
	ft_signal();
	mini->exit_flag = 1;
	mini->home = getenv("HOME");
	mini->envp_list = ft_lstnew(ft_strdup(envp[i]));
	while (envp[++i])
		ft_change_envp(mini, envp[i]);
	ft_check_envp(mini->envp_list);
	if (!ft_search_envp(mini->envp_list, "?"))
	{
		ft_lstadd_back(&mini->envp_list, ft_lstnew(ft_strdup("?=0")));
		ft_lstlast(mini->envp_list)->flag = -1;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void)argc;
	(void)argv;
	ft_init(&mini, envp);
	while (mini.exit_flag)
	{
		ft_username_pars(&mini);
		rl_replace_line("", 0);
		mini.line = readline(mini.username);
		if (mini.line && *mini.line)
			add_history(mini.line);
		if (!mini.line)
		{
			mini.exit_flag = 0;
			ft_putstr_fd(mini.username, 2);
			ft_putstr_fd(BLU"exit\n"END, 2);
		}
		if (mini.line && *mini.line)
			if (!ft_lexer(&mini) && !ft_parser(&mini) && !mini.error)
				ft_proc(&mini);
		ft_free_line_lst_cmd(&mini);
	}
	ft_freelst(mini.envp_list);
	return (0);
}
